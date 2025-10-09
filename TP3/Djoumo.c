#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// FONCTION POUR LA NEGATION DE L'IMAGE

void create_negative(Image_PPM *img)
{
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            img->pixel[i][j].r = img->max_value_color - img->pixel[i][j].r;
            img->pixel[i][j].g = img->max_value_color - img->pixel[i][j].g;
            img->pixel[i][j].b = img->max_value_color - img->pixel[i][j].b;
        }
    }
}
