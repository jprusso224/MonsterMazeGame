#ifndef MONSTER_H
#define MONSTER_H

#include "GameEntity.h"

class Monster : public GameEntity
{
public:
    Monster(Renderer_Ptr renderer);
    virtual ~Monster(){}

    virtual void init();
    virtual void update(){}
    virtual void render();
};

#endif // MONSTER_H
