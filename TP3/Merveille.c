#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// FONCTION SUR LE NIVEAU DE GRIS


void grayscale(Image_PPM *image)
{
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            Pixels *p = &image->pixel[i][j];
            int moyenne = (p->r + p->g + p->b) / 3;
            p->r = p->g = p->b = moyenne;
        }
    }
}