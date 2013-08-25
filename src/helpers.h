#ifndef HELPERS_H
#define HELPERS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>

// Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// The surfaces
extern std::vector<SDL_Surface*> surfaces;
extern SDL_Surface *screen;
extern SDL_Surface *background;
extern SDL_Surface *keen;

SDL_Surface *load_image(std::string filename);

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip);

bool init();

bool load_files();

void set_clips();

void clean_up();

#endif
