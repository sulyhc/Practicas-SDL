/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
//dimesiones de la pantalla

const int SCREEN_WIDTH = 780;
const int SCREEN_HEIGHT = 585;


SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld= NULL;



void testFunction();

bool init();
bool loadMedia();
void close();



int main( int argc, char* args[] )
{

    testFunction();

    init();
    if(loadMedia()){

        bool quit = false;
        SDL_Event e;

        while(!quit){

            while(SDL_PollEvent(&e) != 0){
                if(e.type == SDL_QUIT){
                    quit = true;
                }
            }

            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface( gWindow );

        }







    }



        close();


    return 0;
}




void testFunction(){
printf("INICIADO CHE BOLUDO PELOTUDO");

}

bool init(){
    bool success = true;

    //comporbando si se puede inicializar SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("NO SE PUDO CARGAR SDL");
        success = false;
    }
    else{
        //SDL Window
        gWindow = SDL_CreateWindow("TUTORIAL PARTE 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( gWindow == NULL ){
            printf("NO SE PUDO CREAR LA VENTANA CON SDL");
            success = false;
        }

        else{
            //get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }

    }

    return success;


}

bool loadMedia(){

    bool success = true;

    gHelloWorld = SDL_LoadBMP("img/test.bmp");

    if( gHelloWorld == NULL ){

        printf("NO SE PUDO CARGAR LA IMAGEN");
        success = false;

    }

    return success;

}

void close(){

    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    SDL_Quit();

}
