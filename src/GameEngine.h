#include <stdio.h>
#include <stdlib.h>

void GameEngine_Quit(void) {
    printf("%s\n", SDL_GetError());
    exit(1);
}

