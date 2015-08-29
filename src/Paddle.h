#include "SDL.h"
#include "GameObject.h"

typedef struct _Paddle_s * Paddle;

GameObject Paddle_Create(SDL_Renderer *renderer, int x, int y, int w, int h);

