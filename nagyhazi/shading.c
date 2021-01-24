#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "loadimage.h"
#include "shading.h"
#include "sub.h"


void darker(PPMimage image)
{
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
            /*0.9-el szorzas 10%-os sotetitesert,float eredmeny int visszacastolasa*/
            image.PPMpixeldata[i][j].r=(int)(image.PPMpixeldata[i][j].r*0.9);
            image.PPMpixeldata[i][j].g=(int)(image.PPMpixeldata[i][j].g*0.9);
            image.PPMpixeldata[i][j].b=(int)(image.PPMpixeldata[i][j].b*0.9);
        }
    }
}
void lighter(PPMimage image)
{
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
            /*1.1-el szorzas 10%-os fenyerositesert,float eredmeny int visszacastolasa*/

            image.PPMpixeldata[i][j].r=(int)truncate((image.PPMpixeldata[i][j].r*1.1));

            image.PPMpixeldata[i][j].g=(int)truncate((image.PPMpixeldata[i][j].g*1.1));

            image.PPMpixeldata[i][j].b=(int)truncate((image.PPMpixeldata[i][j].b*1.1));

        }
    }
}
/*A kontrasztmódosító függvény forrása:http://thecryptmag.com/Online/56/imgproc_5.html*/
void morecontrast(PPMimage image)
{
    int contrast=30;
    float factor=(259.0*(contrast+255.0))/(255.0*(259.0-contrast));
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
                image.PPMpixeldata[i][j].r=(int)truncate(factor*(image.PPMpixeldata[i][j].r-128)+128);

                image.PPMpixeldata[i][j].g=(int)truncate(factor*(image.PPMpixeldata[i][j].g-128)+128);

                image.PPMpixeldata[i][j].b=(int)truncate(factor*(image.PPMpixeldata[i][j].b-128)+128);

        }
    }
}
void lesscontrast(PPMimage image)
{
    int contrast=-30;
    float factor=(259.0*(contrast+255.0))/(255.0*(259.0-contrast));
    for(int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
                image.PPMpixeldata[i][j].r=(int)truncate(factor*(image.PPMpixeldata[i][j].r-128)+128);

                image.PPMpixeldata[i][j].g=(int)truncate(factor*(image.PPMpixeldata[i][j].g-128)+128);

                image.PPMpixeldata[i][j].b=(int)truncate(factor*(image.PPMpixeldata[i][j].b-128)+128);

        }
    }
}

