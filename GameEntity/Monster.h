#ifndef MONSTER_H
#define MONSTER_H

#include <QTimer>

#include "GameEntity.h"

enum RandomMonsterEvent : int
{
    MOVE_LEFT = 0,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    IDLE
};
static const int RANDOM_MONSTER_EVENT_COUNT = 4;

class Monster : public GameEntity
{

public:
    Monster(Renderer_Ptr renderer);
    virtual ~Monster(){}

    virtual void init();
    virtual void processInput(ProcessInputType input){Q_UNUSED(input)} /*Monsters don't care about input*/
    virtual void update(uint32_t currTime_ms);
    virtual void render();

    virtual void attack();

    int getFireRate() const {return m_fireRate;}
    void setFireRate(int fireRate){m_fireRate = fireRate;}

private:

    int m_fireRate;

    void handleEventTimeout();
    uint32_t lastEventTime_ms;
    uint32_t lastFireTime_ms;

};

#endif // MONSTER_H
