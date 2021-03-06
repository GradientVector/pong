#ifndef GAMEOBJECTPRIVATE_H
#define GAMEOBJECTPRIVATE_H

#include <SDL.h>
#include "GameObject.h"

typedef struct _GameObjectInterface_s {
    void (*Destroy)(GameObject self);
    void (*Update)(GameObject self);
    void (*Draw)(GameObject self);
} GameObjectInterface_s;

typedef struct _GameObject_s {
    GameObjectInterface vtable;
    SDL_Renderer *renderer;
    int x, y; // position
    int w, h; // width, height
} GameObject_s;

#endif // GAMEOBJECTPRIVATE_H
