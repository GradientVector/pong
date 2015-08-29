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

#define PADDLE_MIN_Y 0
#define PADDLE_MAX_Y (SCREEN_HEIGHT - PADDLE_HEIGHT)

#define PADDLE_1_X 0
#define PADDLE_2_X (SCREEN_WIDTH - PADDLE_WIDTH)

#define PADDLE_SPEED 5

#define UPDATE_TICKS 10

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
    GameObject paddle1 = Paddle_Create(renderer, PADDLE_1_X, 20, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED, PADDLE_MIN_Y, PADDLE_MAX_Y);
    GameObject paddle2 = Paddle_Create(renderer, PADDLE_2_X, 200, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED, PADDLE_MIN_Y, PADDLE_MAX_Y);
    
    // Enter game loop
    bool done = false;
    uint32_t last = 0;
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
        uint32_t now = SDL_GetTicks();
        // check if overflow occured on the time
        if (now > last + UPDATE_TICKS || (now < last && (now + UINT32_MAX - last > UPDATE_TICKS))) {
            GameObject_Update(paddle1);
            GameObject_Update(paddle2);
            last = now;
        }
        
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
