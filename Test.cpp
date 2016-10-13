#include <SDL.h>
#include <stdio.h>

//dimesiones de la pantalla

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



int main(int argc, char* args[]){

    //ventana quye sera renderizada
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;


    //inicializa SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0 ){

        printf("NO JALO ESTA MADRE ESE MEN");

    }else{

        window = SDL_CreateWindow("TUTORIAL CHINGON DE SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(window == NULL){
            printf("NO SE HIZO NI MADRES BATO");
        }

        else{

            //obtiene surface del objecto llamado window creado anteriormente
            screenSurface = SDL_GetWindowSurface(window);

            //Pone la superficie blancaq
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            //actualiza la superficie
            SDL_UpdateWindowSurface(window);


            //delay
            SDL_Delay(2000);





        }







    }

//destruye la ventana

            SDL_DestroyWindow(window);

            SDL_Quit();

            return 0;


}
