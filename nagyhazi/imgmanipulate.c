#include <stdio.h>
#include <stdlib.h>
#include "loadimage.h"
#include "shading.h"
#include "imgmanipulate.h"
#include "sub.h"
#include "shading.h"
void negative(PPMimage image)
{
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
            image.PPMpixeldata[i][j].r=255-image.PPMpixeldata[i][j].r; /* A negativ szin eleresehez át kell ugrani a színskála ellentétes oldalára->255-eredeti ertek*/
            image.PPMpixeldata[i][j].g=255-image.PPMpixeldata[i][j].g;
            image.PPMpixeldata[i][j].b=255-image.PPMpixeldata[i][j].b;
        }
    }
}

void pink(PPMimage image)
{
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
            image.PPMpixeldata[i][j].r=truncate(image.PPMpixeldata[i][j].r+85); /* A szinskala eltolasa piros iranyba->pink effekt*/
            image.PPMpixeldata[i][j].g=truncate(image.PPMpixeldata[i][j].g-20);
            image.PPMpixeldata[i][j].b=truncate(image.PPMpixeldata[i][j].b-20);
        }
    }
}
void mirrorvertical(PPMimage image)
{
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
            image.PPMpixeldata[i][j]=image.PPMpixeldata[i][image.width-j-1]; /* -1 levonasa azert,hogy ne fusson tul a ciklus a tombon*/
        }                                                                    /* Felcsereli az i. sor j. tagját a vele szimmetrikusan szemben levovel*/
    }
}
void mirrorhorizontal(PPMimage image)
{
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
            image.PPMpixeldata[i][j]=image.PPMpixeldata[image.height-i-1][j]; /* -1 levonasa azert, hogy ne fusson tul a cilus a tombon*/
        }                                                                     /* Felcsereli az i. sor j. tagját a vele azonos oszlopban levo,vizszintes kozepvonaltol
                                                                                    azonos tavolsagra levo ponttal*/
    }
}
void deepfry (PPMimage image)
{
    morecontrast(image);
    pink(image);
    negative(image);
    morecontrast(image);
    morecontrast(image);
    pink(image);
    negative(image);
    morecontrast(image);
    morecontrast(image);
    lighter(image);
    negative(image);
    morecontrast(image);
    pink(image);
    lesscontrast(image);
    negative(image);
    for(int i=0;i<8;i++)
        morecontrast(image);
}

