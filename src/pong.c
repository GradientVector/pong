#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>

#define TITLE "pong"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(void) {
    // SDL_Init must be called before most other SDL functions
    // Event Handling, File I/O, and Threading are initialized by default.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return 1; // Exit early with error
    }

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, 
                                SCREEN_HEIGHT, 
                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, 
                                &window, 
                                &renderer);
    SDL_SetWindowTitle(window, TITLE);

    // clear screen to black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

    // make the scaled rendering look smoother
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    // Enter game loop
    bool done = false;
    while (!done) {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // check for messages
            switch (event.type) {
                case SDL_QUIT: // exit if the window is closed  
                    done = true;
                    break;
                case SDL_KEYDOWN:
                    // handle key presses
                    break;
                default:
                    break;
            }
        }
        // Do game update
        // Update graphics
        // Update input
    }

    // Do exit cleanup

    // Must be called before an SDL application exits to safely shut down all subsystems.
    SDL_Quit();

	return EXIT_SUCCESS;
}
