#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity
{
public:
    Player(Renderer_Ptr renderer);
    virtual ~Player() {}

    virtual void init();
    virtual void update(){}
    virtual void render();

private:

};

#endif // PLAYER_H
