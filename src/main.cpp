#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

#include "helpers.h"

int main (int argc, char** args) {
    bool running = true;
    SDL_Event event;

    // Initialization
    if (!init()) return 1;

    while (running) {
        // Handle user input

        // For non-game-related commands, like pressing Esc to get to the menu,
        // call that function separately here.

        // For game-related keypresses, pass it as a parameter...? into the
        // game processing loop.

        if (SDL_PollEvent(&event)) {
            // If a key was pressed
            if (event.type == SDL_KEYDOWN) {

            }

            // If the user X'd out of the window
            else if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Call game processing
    }

    // Prepare for quit
    clean_up();

    return 0;
}
