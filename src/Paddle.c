#include "Paddle.h"
#include "GameObjectPrivate.h"
#include "GameEngine.h"

typedef struct _Paddle_s {
    GameObject_s base;
} Paddle_s;

static void destroy(GameObject base) { 
    free(base);
}

static void update(GameObject base, int x, int y) {
    base->x = x;
    base->y = y;
}

static void draw(GameObject base) { 
    // Paddle self = (Paddle)base;
    SDL_Renderer *renderer = base->renderer;
    if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) < 0) { GameEngine_Quit(); }
    SDL_Rect rectangle;
    rectangle.x = base->x; // self->base.x;
    rectangle.y = base->y; // self->base.y;
    rectangle.w = base->w; // self->base.w;
    rectangle.h = base->h; // self->base.h;
    if (SDL_RenderFillRect(renderer, &rectangle) < 0) { GameEngine_Quit(); }
}

static GameObjectInterface_s interface = {
    .Destroy = destroy,
    .Update = update,
    .Draw = draw,
};

GameObject Paddle_Create(SDL_Renderer *renderer, int x, int y, int w, int h) {
    Paddle self = calloc(1, sizeof(Paddle_s));
    self->base.vtable = &interface;
    self->base.renderer = renderer;
    self->base.x = x;
    self->base.y = y;
    self->base.w = w;
    self->base.h = h;
    return (GameObject)self;
}

