#include <SDL.h>
#include "GameObject.h"

typedef struct _GameObjectInterface_s {
    void (*Destroy)(GameObject self);
    void (*Update)(GameObject self, int x, int y);
    void (*Draw)(GameObject self);
} GameObjectInterface_s;

typedef struct _GameObject_s {
    GameObjectInterface vtable;
    SDL_Renderer *renderer;
    int x, y; // position
    int w, h; // width, height
} GameObject_s;

