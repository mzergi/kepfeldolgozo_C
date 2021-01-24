#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "loadimage.h"
#include "sub.h"
void imagewriter(char* filename,PPMimage image)
{
    FILE* fp;
    fp = fopen(filename,"wb");
    fprintf(fp,"P6\n");  /* A "magic number" beírása, mivel PPM fájlokat olvasunk ez mindig P6 */
    fprintf(fp,"%d ",image.width);  /* szélesség beírása a fájlba */
    fprintf(fp,"%d\n",image.height);    /* Magasság beírása a fájlba */
    fprintf(fp,"%d\n",image.maxval);    /* Maxval beírása a fájlba */

    /* Pixeladatok beírása a fájlba, a megfelelő sor és oszlop szerint */

    for (int i=0; i<image.height; i++)
    {
        for(int j=0; j<image.width; j++)
        {
            fwrite(&image.PPMpixeldata[i][j].r,1,1,fp);
            fwrite(&image.PPMpixeldata[i][j].g,1,1,fp);
            fwrite(&image.PPMpixeldata[i][j].b,1,1,fp);
        }
    }
    /* A már felhasznált dinamikusan foglalt kétdimenziós tömb felszabadítása*/
    for (int y=0; y<image.height; ++y)
        free(image.PPMpixeldata[y]);
    free(image.PPMpixeldata);
    fclose(fp);
}
