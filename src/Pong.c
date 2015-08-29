#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "Paddle.h"

#define TITLE "pong"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 80

int main(void) {
    // SDL_Init must be called before most other SDL functions
    // Event Handling, File I/O, and Threading are initialized by default.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return 1; // Exit early with error
    }
    // Must be called before an SDL application exits to safely shut down all subsystems.
    atexit(SDL_Quit);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, 
                                SCREEN_HEIGHT, 
                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, 
                                &window, 
                                &renderer);
    SDL_SetWindowTitle(window, TITLE);

    // make the scaled rendering look smoother
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    // create the game objects
    GameObject paddle1 = Paddle_Create(renderer, 0, 20, PADDLE_WIDTH, PADDLE_HEIGHT);
    GameObject paddle2 = Paddle_Create(renderer, SCREEN_WIDTH-PADDLE_WIDTH, 200, PADDLE_WIDTH, PADDLE_HEIGHT);
    
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
        // clear screen to black
	    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RenderClear(renderer);
        // draw paddles
        GameObject_Draw(paddle1);
        GameObject_Draw(paddle2);

	    SDL_RenderPresent(renderer); // update the window

        // Update input
    }

    // Do exit cleanup

	return EXIT_SUCCESS;
}
