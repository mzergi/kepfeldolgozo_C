#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "loadimage.h"
#include "sub.h"

PPMimage imagereader (char* filename)
{
    FILE* fp;
    PPMimage image;
    fp = fopen(filename,"rb");
    if(fp==NULL)
    {
        printf("Nem sikerult megnyitni a fajlt\n");
        image.height=0;
        image.width=0;
        image.PPMpixeldata=NULL;
        image.maxval=0;
        return image;     /* Ha nem létezik a fájl amit be szeretnénk olvasni, akkor üres képet ad vissza*/
    }
    /*Magic number beolvasasa,esetunkben mindig P6,de lehetne ezt is hasznalni*/
    char magic[4];
    fgets(magic,3,fp);
    magic[2]='\n';
    magic[3]='\0';
    fseek (fp,sizeof(char),SEEK_CUR);
    /*  Kommentek átugrása, komment utáni új sor elejének ellenőrzése, ha komment akkor átugorjuk, ha nem komment
        visszalépünk egyet. */
    char buff='\n';
    while(buff=='\n')
    {
        fscanf(fp,"%c",&buff);
        if(buff!='#'){
            fseek(fp,-sizeof(char),SEEK_CUR);     /* %c és %d méretkülönbségekből adódó problémákat nem tudtam megoldani az fseek kiszedéséhez*/
            break;
        }
        else
        {
            while(buff!='\n')
            {
                fscanf(fp,"%c",&buff);
            }
        }
    }

    /* Magasság és szélesség beolvasása, egy-egy integer változóba*/
    int width;
    fscanf(fp,"%d",&width);
    int height;
    fscanf(fp,"%d",&height);

    /* A pixelek maximum r,g,b értékének beolvasása,esetünkben mindig 255*/
    int maxval;
    fscanf(fp,"%d",&maxval);
    fscanf(fp,"%c",&buff); /* A maxval utáni \n átugrása, mivel azt az fscanf %d-re már nem olvassa be*/
    /*Adatok szamara memoriafoglalas ket dimenzios tombbe*/
    pixel** pixeldata;
    pixeldata = (pixel**) calloc(height,sizeof(pixel*));
    for(int y=0; y<height; ++y)
    {
        pixeldata[y] = (pixel*) calloc(width,sizeof(pixel));
    }
    /*Adatok beolvasasa a kepfajlbol 8 bitenkent,r,g,b sorrendben,
        a megfelelo sorok es oszlopok szerint      */
    for (int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            fread(&pixeldata[i][j].r,1,1,fp);
            fread(&pixeldata[i][j].g,1,1,fp);
            fread(&pixeldata[i][j].b,1,1,fp);
        }
    }

    /* A beolvasott adatok beírása a kép struktúrába */

    image.width=width;
    image.height=height;
    image.maxval=maxval;
    image.PPMpixeldata=pixeldata;

    printf("Sikeres beolvasas\n");
    fclose(fp);
    return image;
}
