#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>

#include "helpers.h"
#include "Timer.h"
#include "Player.h"

int main (int argc, char **args) {
    // Redirect stdout back to console
    FILE *ctt = fopen("CON", "w");
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);

    // Initialize variables
    bool running = true;
    SDL_Event event;
    Timer fps;

    // Initialize SDL
    if (!init()) return 1;
    if (!load_files()) return 1;

    apply_surface(0, 0, background, screen, NULL);
    //apply_surface(0, 0, keen, screen, NULL);
    SDL_Flip(screen);

    // Create player object
    Player character;

    while (running) {
        // Start timer
        fps.start();

        // Handle user input

        // For non-game-related commands, like pressing Esc to get to the menu,
        // call that function separately here.

        // For game-related keypresses, pass it as a parameter...? into the
        // game processing loop.

        if (SDL_PollEvent(&event)) {
            // If a key was pressed
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE: running = false; break;
                    case SDLK_RIGHT: character.set_state(WALKR); break;
                    case SDLK_DOWN: character.set_state(STANDR); break;
                }
            }

            // If the user X'd out of the window
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Fill the screen white
        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

        // Call game processing
        character.draw();

        // Update screen
        if (SDL_Flip(screen) == -1) return 1;

        // Cap frame rate
        if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
            SDL_Delay((1000/FRAMES_PER_SECOND) - fps.get_ticks());
    }

    // Prepare for quit
    clean_up();
    //fclose(ctt);  // This crashes PowerShell...

    return 0;
}
