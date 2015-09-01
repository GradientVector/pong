#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>
#include "GameObject.h"

typedef struct _Paddle_s * Paddle;

GameObject Paddle_Create(SDL_Renderer *renderer, int x, int y, int w, int h, int speed, int min_y, int max_y);

#endif // PADDLE_H
