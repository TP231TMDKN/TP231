#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// FONCTION POUR LE DOMINANT
//-----------------------------------
int verifie_value(int value, int min, int max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

void put_dominant_color(Image_PPM *image, char dominant_color, int value)
{
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            Pixels *p = &image->pixel[i][j];

            // Check if this pixel has the specified dominant color
            if ((dominant_color == 'R' && p->r >= p->g && p->r >= p->b) ||
                (dominant_color == 'G' && p->g >= p->r && p->g >= p->b) ||
                (dominant_color == 'B' && p->b >= p->r && p->b >= p->g))
            {
                // Verifie juste si la nouvelle valeur n'est pas < 0 ou > max_value_color
                p->r = verifie_value(p->r + value, 0, image->max_value_color);
                p->g = verifie_value(p->g + value, 0, image->max_value_color);
                p->b = verifie_value(p->b + value, 0, image->max_value_color);
            }
        }
    }
}
