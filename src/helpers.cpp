#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
#include <vector>

#include "helpers.h"

using namespace std;

// Surfaces
vector<SDL_Surface*> surfaces;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *keen = NULL;

// Surface clips
SDL_Rect clipsRight[5];
SDL_Rect clipsLeft[5];

SDL_Surface *load_image(std::string filename) {
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;

    // Load image
    loadedImage = IMG_Load(filename.c_str());

    // If nothing went wrong loading the image
    if (loadedImage != NULL) {
        // Create an optimized image
        optimizedImage = SDL_DisplayFormat(loadedImage);

        // Free old image
        SDL_FreeSurface(loadedImage);

        // Make sure image was optimized
        if (optimizedImage != NULL) {
            // Map the color key
            // ... to be determined
            Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);

            // Set all pixels of colorkey color to be transparent
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
        }
    }
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip=NULL) {
    // Make a temp rect to hold the offsets
    SDL_Rect offset;

    // Give the offsets to the rect
    offset.x = x;
    offset.y = y;

    // Blit the surface
    SDL_BlitSurface(source, clip, destination, &offset);
}

bool init() {
    // Init all SDL subsystems
    if (SDL_Init( SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO ) == -1) return false;

    // Init IMG
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if (initted&flags != flags) {
        printf("Couldn't init SDL_image.\n");
        printf("%s\n", IMG_GetError());
    }

    // Set up screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    // Make sure screen was successfully set up
    if (screen == NULL) return false;

    // Add screen to surfaces
    surfaces.push_back(screen);

    // Initialize SDL_ttf
    if (TTF_Init() == -1) return false;

    // Set window caption
    SDL_WM_SetCaption("Commander Keen 5", NULL);

    // Update screen
    SDL_Flip(screen);

    return true;
}

bool load_files() {
    // Load images
    background = load_image("../data/background.png");
    keen = load_image("../data/keensprite.png");

    // Make sure load worked
    if (background == NULL) {
        printf("background.png failed to load.\n");
        return false;
    }

    // Add to surfaces
    surfaces.push_back(background);
    surfaces.push_back(keen);

    // Open the fonts
    //TTF_Font *font = TTF_OpenFont ("lazy.ttf", 28);

    //if (font == NULL) return false;

    return true;
}

void clean_up() {
    // Free images
    for (vector<SDL_Surface*>::iterator i=surfaces.begin(); i!=surfaces.end(); ++i) {
        SDL_FreeSurface(*i);
    }

    // Close font
    //TTF_CloseFont(font);

    // Quit SDL_TTF
    TTF_Quit();

    // Quit SDL
    SDL_Quit();
}
