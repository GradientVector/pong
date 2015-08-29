#include "Paddle.h"
#include "GameObjectPrivate.h"
#include "GameEngine.h"

typedef struct _Paddle_s {
    GameObject_s base;
    int speed;
    int min_y;
    int max_y;
} Paddle_s;

static void destroy(GameObject base) { 
    free(base);
}

static void flipDirection(Paddle self) {
    self->speed *= -1;
}

static void update(GameObject base) {
    Paddle self = (Paddle)base;
    int new_y = base->y + self->speed;
    // Check for boundaries
    if (new_y >= self->max_y) { 
        new_y += (new_y - self->max_y);
        flipDirection(self);
    }
    else if (new_y < self->min_y) { 
        new_y += (self->min_y - new_y);
        flipDirection(self);
    }

    base->y = new_y;
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

GameObject Paddle_Create(SDL_Renderer *renderer, int x, int y, int w, int h, int speed, int min_y, int max_y) {
    Paddle self = calloc(1, sizeof(Paddle_s));
    self->base.vtable = &interface;
    self->base.renderer = renderer;
    self->base.x = x;
    self->base.y = y;
    self->base.w = w;
    self->base.h = h;
    self->speed = speed;
    self->min_y = min_y;
    self->max_y = max_y;
    return (GameObject)self;
}

