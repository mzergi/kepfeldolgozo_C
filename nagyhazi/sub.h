#ifndef SUB_H
#define SUB_H

typedef struct pixel
{
    int r,g,b;      /* char-ban t�rolva a f�ggv�nyek haszn�latakor t�lfolyik a tartom�nyon a felszorzott �tmeneti �rt�k */
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
