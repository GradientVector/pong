typedef struct _GameObject_s * GameObject;
typedef struct _GameObjectInterface_s * GameObjectInterface;

void GameObject_Destroy(GameObject self);
void GameObject_Update(GameObject self);
void GameObject_Draw(GameObject self);

