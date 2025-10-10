#ifndef __MAIN_H__
#define __MAIN_H__

typedef struct
{
    unsigned char r, g, b;
} Pixels;

typedef struct image
{
    char version[3];
    int height;
    int width;
    int max_value_color;
    Pixels **pixel;
} Image_PPM;

void create_negative(Image_PPM *img);
void put_dominant_color(Image_PPM *image, char dominant_color, int value);
void grayscale(Image_PPM *image);
void apply_median_filter(Image_PPM *image);
Image_PPM *cut_image(Image_PPM *image, int l1, int l2, int c1, int c2);

#endif
