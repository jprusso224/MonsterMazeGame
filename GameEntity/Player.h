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

    /*
     * Need to return by reference so the object layer can remove them
     * upon collision. Don't forget to delete!
     */
    QList<Projectile*> getProjectiles(){return projectileList;}
    void removeProjectiles(QList<int> projectileIdxToRemove);

private:

    QList<Projectile*> projectileList;

};

#endif // PLAYER_H
