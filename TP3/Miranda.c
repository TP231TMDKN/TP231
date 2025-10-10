#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// FONCTION DE DECOUPAGE DE L'IMAGE

Image_PPM *cut_image(Image_PPM *image, int l1, int l2, int c1, int c2)
{
    // Verification des coordonnees
    if (l1 < 0 || l2 > image->height || c1 < 0 || c2 > image->width || l1 >= l2 || c1 >= c2)
    {
        printf(" Coordonnees invalides pour le decoupage !\n");
        free_image(image);
        return NULL;
    }

    // Allocation de la nouvelle image
    Image_PPM *cropped = (Image_PPM *)malloc(sizeof(Image_PPM));
    strcpy(cropped->version, image->version);
    cropped->width = c2 - c1 + 1;
    cropped->height = l2 - l1 + 1;
    cropped->max_value_color = image->max_value_color;

    // Allocation memoire pour les pixels
    cropped->pixel = (Pixels **)malloc(cropped->height * sizeof(Pixels *));
    for (int i = 0; i < cropped->height; i++)
    {
        cropped->pixel[i] = (Pixels *)malloc(cropped->width * sizeof(Pixels));
        for (int j = 0; j < cropped->width; j++)
        {
            cropped->pixel[i][j] = image->pixel[l1 + i][c1 + j];
        }
    }

    return cropped;
}
