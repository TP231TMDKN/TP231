#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./main.h"
#include "./Djoumo.c"
#include "./Vicky.c"
#include "./merveille.c"
#include "./Kabod.c"
#include "./Miranda.c"

#define max_arg 10
#define max_command 255


void ignore_comment(FILE *file)
{
    int char_file;
    while ((char_file = fgetc(file)) == '#')
    {
        // Lire jusqu'à la fin de la ligne
        while ((char_file = fgetc(file)) != '\n' && char_file != EOF)
            ;
    }
    // Remettre le dernier caractère lu
    if (char_file != EOF)
    {
        ungetc(char_file, file);
    }
}

int save_image(char *filename, Image_PPM *img)
{
    FILE *fichier = fopen(filename, "w");
    if (!fichier)
    {
        fprintf(stderr, "Erreur de creatioon du fichier.\n");
        return 0;
    }

    fprintf(fichier, "%s\n", img->version);
    fprintf(fichier, "%d %d\n", img->width, img->height);

    fprintf(fichier, "%d\n", img->max_value_color);

    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            fprintf(fichier, "%d %d %d",
                    img->pixel[i][j].r,
                    img->pixel[i][j].g,
                    img->pixel[i][j].b);
            if (j < img->width - 1)
                fprintf(fichier, " ");
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
    return 1;
}

Image_PPM *take_infos(char *name)
{
    FILE *file = fopen(name, "r");
    if (!file)
    {
        perror("Erreur Impossible d'ouvrir le fichier.\n");
        return NULL;
    }
    Image_PPM *img = malloc(sizeof(Image_PPM));
    if (!img)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        fclose(file);
        return NULL;
    }
    // Lire la version
    ignore_comment(file);
    fscanf(file, "%2s", img->version);
    if (strcmp(img->version, "P3") != 0)
    {
        printf("Erreur : seul le format P3 est supporté\n");
        free(img);
        fclose(file);
        return NULL;
    }
    // Lire largeur, hauteur et valeur max
    fscanf(file, "%d %d", &img->width, &img->height);
    ignore_comment(file);
    fscanf(file, "%d", &img->max_value_color);
    // Allouer la mémoire pour les pixels
    img->pixel = (Pixels **)malloc(img->height * sizeof(Pixels *));
    if (!img->pixel)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(img);
        fclose(file);
        return NULL;
    }
    for (int i = 0; i < img->height; i++)
    {
        img->pixel[i] = (Pixels *)malloc(img->width * sizeof(Pixels));
        if (!img->pixel[i])
        {
            // Libérer la mémoire en cas d'erreur
            for (int k = 0; k < i; k++)
                free(img->pixel[k]);
            free(img->pixel);
            free(img);
            fclose(file);
            return NULL;
        }
    }

    // Lire les pixels
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            int r, g, b;
            fscanf(file, "%d %d %d", &r, &g, &b);
            img->pixel[i][j].r = (unsigned char)r;
            img->pixel[i][j].g = (unsigned char)g;
            img->pixel[i][j].b = (unsigned char)b;
        }
    }
    fclose(file);
    return img;
}

//-----------------------------------
// Fonctions des differentes taches:
//-----------------------------------
//____DIMITRI et Assemblage de toutes les fonctions et creation du main().
void get_size(Image_PPM *img)
{
    printf("%d x %d\n", img->width, img->height);
}

//-------------------------------------
int take_command(char *command)
{
    char *args[max_arg];
    char copy_command[max_command];
    strcpy(copy_command, command);
    char *token = strtok(copy_command, " \n");
    int arg_count = 0;

    while (token != NULL && arg_count < max_arg)
    {
        args[arg_count++] = token;
        token = strtok(NULL, " \n");
    }

    if (arg_count == 0)
    {
        return 0;
    }
    args[arg_count] = NULL;

    if (strcmp(args[0], "quit") == 0)
    {
        printf("A bientot🖐️.\n");
        exit(0);
    }
    else if (strcmp(args[0], "cut") == 0 && arg_count == 7)
    {
        Image_PPM *img = take_infos(args[1]);
        if (img)
        {
            int l1 = atoi(args[2]);
            int c1 = atoi(args[4]);
            int l2 = atoi(args[3]);
            int c2 = atoi(args[5]);
            Image_PPM *image_cut = cut_image(img, l1, l2, c1, c2);
            if (image_cut && save_image(args[6], image_cut))
            {
                printf("Opération effectuée avec succes✅!\n");
            }
            else
            {
                printf("Erreur lors du decoupage⚠️.\n");
            }
            free_image(image_cut);
            free_image(img);
        }
        else
        {
            printf("Fichier introuvable\n");
        }
    }
    else if (strcmp(args[0], "size") == 0 && arg_count == 2)
    {
        Image_PPM *img = take_infos(args[1]);
        if (img)
        {
            get_size(img);
            free_image(img);
        }
        else
        {
            printf("Fichier non trouvé.\n");
        }
    }
    else if (strcmp(args[0], "gris") == 0 && arg_count == 2)
    {
        Image_PPM *img = take_infos(args[1]);
        if (img)
        {
            grayscale(img);
            char out[256];
            sprintf(out, "%s_gris.ppm", args[1]);
            if (save_image(out, img))
            {
                printf("Opération effectuée avec succès✅.\n");
            }
            free_image(img);
        }
        else
        {
            printf("Fichier non trouvé.\n");
        }
    }
    else if (strcmp(args[0], "dom") == 0 && arg_count == 4)
    {
        Image_PPM *img = take_infos(args[3]);
        if (img)
        {
            put_dominant_color(img, args[1][0], atoi(args[2]));
            char output[256];
            sprintf(output, "%s_dom.ppm", args[3]);
            if (save_image(output, img))
            {
                printf("Opération effectuée avec succès✅.\n");
            }
            free_image(img);
        }
        else
        {
            printf("Fichier non trouvé.\n");
        }
    }
    else if (strcmp(args[0], "neg") == 0 && arg_count == 3)
    {
        Image_PPM *img = take_infos(args[1]);
        if (img)
        {
            create_negative(img);
            if (save_image(args[2], img))
            {
                printf("Opération effectuée avec succès✅.\n");
            }
            else
            {
                printf("Erreur lors de sauvegarde de la negation.\n");
            }
            free_image(img);
        }
        else
        {
            printf("Fichiers non trouvé.\n");
        }
    }
    else if (strcmp(args[0], "fil") == 0 && arg_count == 3)
    {
        Image_PPM *image = take_infos(args[1]);
        if (image)
        {
            apply_median_filter(image);
            if (save_image(args[2], image))
            {
                printf("opération effectuée\n");
            }
            free_image(image);
        }
        else
        {
            printf("fichier non trouvé\n");
        }
    }
    else
    {
        printf("Commande non reconnue : %s.\n", args[0]);
    }

    return 1;
}

int main()
{
    printf("Application de traitement d'images PPM réalisé par Dimitri.\n");

    while (1)
    {
        char command[max_command];
        printf("ppmviewer > ");

        if (fgets(command, max_command, stdin) == NULL)
        {
            break;
        }

        take_command(command);
    }
}