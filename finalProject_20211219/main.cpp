#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();//Starts up SDL and creates window
bool loadMedia();//Loads media
void close();//Frees media and shuts down SDL

SDL_Window* gWindow = NULL;//The window we'll be rendering to
SDL_Surface* gScreenSurface = NULL;//The surface contained by the window
SDL_Surface* gHelloWorld = NULL;//The image we will load and show on the screen

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
int main(int argc, char* args[] ) {
    if(!init())
    {
        printf( "Failed to load in!\n" );
        return 0;
    }
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
    SDL_UpdateWindowSurface( gWindow );

    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    while(true){
    //remember to initialize the player data
    callMenu();
    chooseLevel();//from novice to expert

     //start the game
        loadMap();//including buildings, roads, trafficLight, and infoBoard; bool bus = false)
        bool gamePause = false;
        while(true){
        update(); //pedestrian's emotion, pedestrian's pos, bus pos, time+=dt, traffic light

        if(press pause) {
            gamePause = true;
        }
        if(bus.arrive && gamePause){
            //play button change to pause button
            while(gamePause == true){

                if(press pause) gamePause = false;
            }
            //play button change to pause button
        }
        if(pedestriansEmotion.scale>=100){
        loseGame();
        break;
        }
        if(time>=surviveMaxTime){
        winGame();
        break;
        }
        if(press exit) break;
    }

    }
    close();
    return 0;
}
