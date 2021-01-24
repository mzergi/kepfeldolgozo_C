#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "writeimage.h"
#include "loadimage.h"
#include "shading.h"
#include "imgmanipulate.h"
#include "sub.h"

/* kulon fuggvenybe, hogy olvashatobb legyen *//*FORRAS:INFOC*/
void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("Nem indithato az SDL: %s", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow(felirat, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szeles, magas, 0);
    if (window == NULL)
    {
        SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL)
    {
        SDL_Log("Nem hozhato letre a megjelenito: %s", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}


int main(int argc, char *argv[])
{
    /* ablak létrehozása */
    SDL_Window *window;
    SDL_Renderer *renderer;
    sdl_init("Kepfeldolgozo", 800, 400, &window, &renderer);

    boxRGBA(renderer,0,0,800,600,68,68,68,255);


     boxRGBA(renderer,0,0,200,90,221,221,221,255);
     stringRGBA(renderer,50,40,"Fajl megnyitasa",0,0,0,255);
     boxRGBA(renderer,0,100,200,190,221,221,221,255);
     stringRGBA(renderer,50,140,"Fajl mentese",0,0,0,255);
     boxRGBA(renderer,0,200,200,290,221,221,221,255);
     stringRGBA(renderer,70,240,"Deep fry",0,0,0,255);
     boxRGBA(renderer,600,0,800,90,221,221,221,255);
     stringRGBA(renderer,650,40,"Fenyero +10%",0,0,0,255);
     boxRGBA(renderer,600,100,800,190,221,221,221,255);
     stringRGBA(renderer,650,140,"Fenyero -10%",0,0,0,255);
     boxRGBA(renderer,600,200,800,290,221,221,221,255);
     stringRGBA(renderer,650,240,"Kontraszt +1",0,0,0,255);
     boxRGBA(renderer,600,300,800,390,221,221,221,255);
     stringRGBA(renderer,650,340,"Kontraszt -1",0,0,0,255);
     boxRGBA(renderer,300,0,500,90,221,221,221,255);
     stringRGBA(renderer,360,40,"Negativ",0,0,0,255);
     boxRGBA(renderer,300,100,500,190,221,221,221,255);
     stringRGBA(renderer,360,140,"Get pink",0,0,0,255);
     boxRGBA(renderer,300,200,500,290,221,221,221,255);
     stringRGBA(renderer,320,240,"Vizszintes tukrozes",0,0,0,255);
     boxRGBA(renderer,300,300,500,390,221,221,221,255);
     stringRGBA(renderer,320,340,"Fuggoleges tukrozes",0,0,0,255);




    /* az elvegzett rajzolasok a kepernyore */
    SDL_RenderPresent(renderer);
    printf("Kepfeldolgozo es kepszerkeszto szoftver\nKepet betolteni a ""Fajl megnyitasa"" gombra kattintva, a megfelelo fajlnevet begepelve valaszkent,majd entert nyomva.\nA kepeknek egy mappaban kell lenni az exevel!\nEredeti/keletkezett kepek megtekintese:\"http:\/\/paulcuth.me.uk\/netpbm-viewer\/\"\n\n\n");

    char filename[50]= {0};
    char newname[54]= {0};
    bool load=false;

    PPMimage image;
    int mx; /* mouse state x*/
    int my; /* mouse state y*/
    SDL_Event event;
    /* A nyomógombok érzékelik ha rajtuk van az egér és ezt egy kék árnyalatra váltással jelzik*/
    while (SDL_WaitEvent(&event) && event.type != SDL_QUIT)
    {
        SDL_GetMouseState(&mx,&my);
        if((mx<200)&&(mx>0)&&(my>0)&&(my<90))
        {
            boxRGBA(renderer,0,0,200,90,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<200)&&(mx>0)&&(my>100)&&(my<190))
        {
            boxRGBA(renderer,0,100,200,190,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<200)&&(mx>0)&&(my>200)&&(my<290))
        {
            boxRGBA(renderer,0,200,200,290,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<800)&&(mx>600)&&(my>0)&&(my<90))
        {
            boxRGBA(renderer,600,0,800,90,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<800)&&(mx>600)&&(my>100)&&(my<190))
        {
            boxRGBA(renderer,600,100,800,190,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<800)&&(mx>600)&&(my>200)&&(my<290))
        {
            boxRGBA(renderer,600,200,800,290,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<800)&&(mx>600)&&(my>300)&&(my<390))
        {
            boxRGBA(renderer,600,300,800,390,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<500)&&(mx>300)&&(my>0)&&(my<90))
        {
            boxRGBA(renderer,300,0,500,90,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<500)&&(mx>300)&&(my>100)&&(my<190))
        {
            boxRGBA(renderer,300,100,500,190,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<500)&&(mx>300)&&(my>200)&&(my<290))
        {
            boxRGBA(renderer,300,200,500,290,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        else if((mx<500)&&(mx>300)&&(my>300)&&(my<390))
        {
            boxRGBA(renderer,300,300,500,390,102,153,255,10);
            SDL_RenderPresent(renderer);
        }
        /* Ha egyik gombon sincsen rajta, akkor az eredetit rendereljük*/
        else
        {
            boxRGBA(renderer,0,0,200,90,221,221,221,255);
            stringRGBA(renderer,50,40,"Fajl megnyitasa",0,0,0,255);
            boxRGBA(renderer,0,100,200,190,221,221,221,255);
            stringRGBA(renderer,50,140,"Fajl mentese",0,0,0,255);
            boxRGBA(renderer,0,200,200,290,221,221,221,255);
            stringRGBA(renderer,60,240,"Deep fry",0,0,0,255);
            boxRGBA(renderer,600,0,800,90,221,221,221,255);
            stringRGBA(renderer,650,40,"Fenyero +10%",0,0,0,255);
            boxRGBA(renderer,600,100,800,190,221,221,221,255);
            stringRGBA(renderer,650,140,"Fenyero -10%",0,0,0,255);
            boxRGBA(renderer,600,200,800,290,221,221,221,255);
            stringRGBA(renderer,650,240,"Kontraszt +1",0,0,0,255);
            boxRGBA(renderer,600,300,800,390,221,221,221,255);
            stringRGBA(renderer,650,340,"Kontraszt -1",0,0,0,255);
            boxRGBA(renderer,300,0,500,90,221,221,221,255);
            stringRGBA(renderer,360,40,"Negativ",0,0,0,255);
            boxRGBA(renderer,300,100,500,190,221,221,221,255);
            stringRGBA(renderer,360,140,"Get pink",0,0,0,255);
            boxRGBA(renderer,300,200,500,290,221,221,221,255);
            stringRGBA(renderer,320,240,"Vizszintes tukrozes",0,0,0,255);
            boxRGBA(renderer,300,300,500,390,221,221,221,255);
            stringRGBA(renderer,320,340,"Fuggoleges tukrozes",0,0,0,255);
            SDL_RenderPresent(renderer);
        }
        /* A nyomógombok kattintásérzékelése, kattintásra a funkció meghívása*/
        switch(event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<200)
                    &&(event.button.x>0)&&(event.button.y>0)&&(event.button.y<90))
            {
                printf("Kerem a fajl nevet(.ppm vegzodes nelkul):");
                scanf("%s",&filename);
                strcpy(newname,filename);
                strcat(newname,"_new.ppm");
                strcat(filename,".ppm");
                image=imagereader(filename);
                if(image.width!=0) /* Ha nem sikeres a beolvasás a loadimage üres képet ad vissza, image.width==0*/
                    load=true;     /* A load false-ra van inicializálva */
            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<200)
                    &&(event.button.x>0)&&(event.button.y>100)&&(event.button.y<190))
            {
                if(load==true)
                {
                    imagewriter(newname,image); /*Az imagewriter tartalmaz dinamikusan foglalt memória felszabadítást*/
                    load=false;                 /* mentés után új fájl beolvasására vár majd*/
                    printf("Fajl mentve.\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<200)
                    &&(event.button.x>0)&&(event.button.y>200)&&(event.button.y<290))
            {
                if(load==true)
                {
                    deepfry(image);
                    printf("Dank enough\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<800)
                    &&(event.button.x>600)&&(event.button.y>0)&&(event.button.y<90))
            {
                if(load==true)
                {
                    lighter(image);
                    printf("Fenyero 10%%-al novelve.\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<800)
                    &&(event.button.x>600)&&(event.button.y>100)&&(event.button.y<190))
            {
                if(load==true)
                {
                    darker(image);
                    printf("Fenyero 10%%-al csokkentve.\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<800)
                    &&(event.button.x>600)&&(event.button.y>200)&&(event.button.y<290))
            {
                if(load==true)
                {
                    morecontrast(image);
                    printf("Kontraszt egy egysegnyit novelve.\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");
            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<800)
                    &&(event.button.x>600)&&(event.button.y>300)&&(event.button.y<390))
            {
                if(load==true)
                {
                    lesscontrast(image);
                    printf("Kontraszt egy egysegnyit csokkentve.\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<500)
                    &&(event.button.x>300)&&(event.button.y>0)&&(event.button.y<90))
            {
                if(load==true)
                {
                    negative(image);
                    printf("Negativ letrehozva\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<500)
                    &&(event.button.x>300)&&(event.button.y>100)&&(event.button.y<190))
            {
                if(load==true)
                {
                    pink(image);
                    printf("Pink filter\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<500)
                    &&(event.button.x>300)&&(event.button.y>200)&&(event.button.y<290))
            {
                if(load==true)
                {
                    mirrorhorizontal(image);
                    printf("Vizszintesen tukrozve!\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
            else if((event.button.button == SDL_BUTTON_LEFT)&&(event.button.x<500)
                    &&(event.button.x>300)&&(event.button.y>300)&&(event.button.y<390))
            {
                if(load==true)
                {
                    mirrorvertical(image);
                    printf("Fuggolegesen tukrozve!\n");
                }
                else
                    printf("Nincs meg fajl megnyitva!\n");

            }
        }


    }

    /* ablak bezarasa */
    SDL_Quit();
    /* Ha nem volt mentés de volt betöltés,akkor még fel kell szabadítani a betöltött képet*/
    if(load==true){
        for (int y=0; y<image.height; ++y)
        free(image.PPMpixeldata[y]);
    free(image.PPMpixeldata);
    }

    return 0;
}
