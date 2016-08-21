#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <QStateMachine>

/*
 * States:
 *
 * -Idle
 * -Moving
 * -Jumping
 * -Attacking
 *
 */

class PlayerState
{
public:
    PlayerState();

private:

    QStateMachine* m_stateMachine;

};

#endif // PLAYERSTATE_H
