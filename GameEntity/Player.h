#ifndef PLAYER_H
#define PLAYER_H

#include <QList>

#include "GameEntity.h"

class Player : public GameEntity
{
public:
    Player(Renderer_Ptr renderer);
    virtual ~Player() {}

    virtual void init();
    virtual void processInput(ProcessInputType input);
    virtual void update(uint32_t elapsedTime_ms);
    virtual void render();
    virtual void attack();

private:

    ProcessInputType lastInput;
};

#endif // PLAYER_H
