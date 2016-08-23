#ifndef PLAYER_H
#define PLAYER_H

#include <QList>

#include "GameEntity.h"
#include "Projectile.h"

class Player : public GameEntity
{
public:
    Player(Renderer_Ptr renderer);
    virtual ~Player() {}

    virtual void init();
    virtual void processInput(ProcessInputType input);
    virtual void update(uint32_t currTime_ms);
    virtual void render();

    virtual void attack();

private:

    QList<Projectile*> projectileList;

};

#endif // PLAYER_H
