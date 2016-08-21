#ifndef MONSTER_H
#define MONSTER_H

#include "GameEntity.h"

class Monster : GameEntity
{
public:
    Monster(Renderer_Ptr renderer);
    virtual ~Monster(){}
};

#endif // MONSTER_H
