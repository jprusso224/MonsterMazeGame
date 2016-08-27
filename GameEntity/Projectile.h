#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"

class Projectile : public GameObject
{
public:
    Projectile(Renderer_Ptr renderer, GamePosition pos, GameVelocity vel);

    virtual void init();
    virtual void update(uint32_t elapsedTime_ms);
    virtual void render();


};

#endif // PROJECTILE_H
