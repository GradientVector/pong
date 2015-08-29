#include <stdio.h>
#include <stdlib.h>
#include "GameObjectPrivate.h"

void GameObject_Destroy(GameObject self) { if (self) { self->vtable->Destroy(self); } }
void GameObject_Update(GameObject self) { if (self) { self->vtable->Update(self); } }
void GameObject_Draw(GameObject self) { if (self) { self->vtable->Draw(self); } }

