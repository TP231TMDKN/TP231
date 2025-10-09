#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// FONCTION FAITE PAR KABOD👇👇👇.
//--------------------------------------------------------------
int compare(const void *a, const void *b)
{
    return (*(unsigned char *)a - *(unsigned char *)b);
}
//----------------------------------------------------------------
void free_image(Image_PPM *image)
{
    if (image)
    {
        for (int i = 0; i < image->height; i++)
        {
            free(image->pixel[i]);
        }
        free(image->pixel);
        free(image);
    }
}
//
void apply_median_filter(Image_PPM *image)
{
    // Créer une copie temporaire de l'image
    Image_PPM *temp = malloc(sizeof(Image_PPM));
    temp->width = image->width;
    temp->height = image->height;
    temp->max_value_color = image->max_value_color;
    strcpy(temp->version, image->version);

    // Allouer la mémoire pour la copie
    temp->pixel = malloc(temp->height * sizeof(Pixels *));
    for (int i = 0; i < temp->height; i++)
    {
        temp->pixel[i] = malloc(temp->width * sizeof(Pixels));
        for (int j = 0; j < temp->width; j++)
        {
            temp->pixel[i][j] = image->pixel[i][j]; // Copier chaque pixel
        }
    }

    // Appliquer le filtre médian
    for (int i = 1; i < image->height - 1; i++)
    {
        for (int j = 1; j < image->width - 1; j++)
        {
            unsigned char r_values[9], g_values[9], b_values[9];
            int index = 0;

            // Récupérer les valeurs des voisins (3x3)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    r_values[index] = temp->pixel[i + di][j + dj].r;
                    g_values[index] = temp->pixel[i + di][j + dj].g;
                    b_values[index] = temp->pixel[i + di][j + dj].b;
                    index++;
                }
            }

            // Trier et prendre la médiane
            qsort(r_values, 9, sizeof(unsigned char), compare);
            qsort(g_values, 9, sizeof(unsigned char), compare);
            qsort(b_values, 9, sizeof(unsigned char), compare);

            image->pixel[i][j].r = r_values[4];
            image->pixel[i][j].g = g_values[4];
            image->pixel[i][j].b = b_values[4];
        }
    }

    // Libérer la mémoire temporaire
    free_image(temp);
}