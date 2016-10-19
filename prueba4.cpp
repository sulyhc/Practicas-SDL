#include <SDL.h>
#include <stdio.h>
#include <windows.h>
#include <string>

const int SCREEN_WIDTH = 780;
const int SCREEN_HEIGHT = 585;







enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};


void initMessage();

bool init();
bool loadMedia();


SDL_Surface* loadSurface( std::string path );
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

//image that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//current displayed image
SDL_Surface* gCurrentSurface = NULL;

void close();

void clearScreen();

int main(int argc, char* args[]){

    if(!init()){
        printf("FALLAMOS");
    }else{

        if(!loadMedia()){
            printf("NO SE PUDO CARGAR NADA DE NADA MORRO");
        }
        else{

        bool quit = false;

        SDL_Event e;

        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

        //init with default image
        SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

        SDL_UpdateWindowSurface( gWindow );


        //main bucle

        while(!quit){

            while(SDL_PollEvent(&e) != 0 ){

                if(e.type == SDL_QUIT){
                    quit = true;
                }

                else if(e.type == SDL_KEYDOWN){
                    clearScreen();
                    switch(e.key.keysym.sym){

                    case SDLK_UP:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                        break;

                    case SDLK_DOWN:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                        break;

                    case SDLK_LEFT:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                        break;

                    case SDLK_RIGHT:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                        break;

                    default:
                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                        break;


                    }

                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

                    SDL_UpdateWindowSurface( gWindow );


                }

            }

        }


        close();
    }

    }

}

SDL_Surface* loadSurface(std::string path){

    //load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    printf(path.c_str());
    if( loadedSurface == NULL ){
         printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;

}



void initMessage(){
    printf("INICIADO PRUEBA 4 CHE BOLUDO PELOTUDO");
    Sleep(2000);
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
        gWindow = SDL_CreateWindow("TUTORIAL PARTE 4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
    std::string foler = "img/";

    //default surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] =  loadSurface(foler + "test.bmp" );
    if( gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        success = false;
    }

    //up
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] =  loadSurface(foler + "img1.bmp" );
    if( gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
    {
        success = false;
    }

    //down
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] =  loadSurface(foler + "img2.bmp" );
    if( gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
    {
        success = false;
    }

    //left
    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] =  loadSurface(foler + "img3.bmp" );
    if( gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
    {
        success = false;
    }

    //right
    //down
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] =  loadSurface(foler + "img4.bmp" );
    if( gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        success = false;
    }

    //check if exists error
    if(!success){
        printf("NO SE PUDO CARGAR NI MADRES, REVISA TU CODIGO NO SEAS PENDEJO");
    }


    return success;

}


void close(){

    printf("CERRANDO LA PRUEBA CHE BOLUDO");

    for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++){

        SDL_FreeSurface(gKeyPressSurfaces[i]);
        gKeyPressSurfaces[i] = NULL;

    }

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    printf("HASTA LUEGO ESOS");
    SDL_Quit();

}

void clearScreen(){

   gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

   SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

    SDL_UpdateWindowSurface( gWindow );

}



