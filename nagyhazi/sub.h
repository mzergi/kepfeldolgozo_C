#ifndef SUB_H
#define SUB_H

typedef struct pixel
{
    int r,g,b;      /* char-ban tárolva a függvények használatakor túlfolyik a tartományon a felszorzott átmeneti érték */
} pixel;
typedef struct PPMimage
{
    int width;
    int height;
    int maxval;
    pixel** PPMpixeldata;
} PPMimage;


int truncate (float x);

#endif // SUB_H
