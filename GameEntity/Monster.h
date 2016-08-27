#ifndef MONSTER_H
#define MONSTER_H

#include <QTimer>

#include "GameEntity.h"
#include "Player.h"
#include "GameEventTimer.h"

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
    virtual ~Monster();

    virtual void init();
    virtual void processInput(ProcessInputType input){Q_UNUSED(input)} /*Monsters don't care about input*/
    virtual void update(uint32_t elapsedTime_ms ) override;
    virtual void render();

    virtual void attack();

    void setPlayer(const Player* player){m_player = player;}

    int getFireRate() const {return m_fireRate;}
    void setFireRate(int fireRate){m_fireRate = fireRate;}

private:

    int m_fireRate;

    /*timed events*/
    GameEventTimer* m_movementTimer;
    GameEventTimer* m_attackTimer;

    void handleEventTimeout();

    /*Must have const reference to player, can never change player*/
    const Player* m_player;

};

#endif // MONSTER_H
