#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameTypes.h"

class GameObject
{
public:
    GameObject(Renderer_Ptr renderer);

    virtual void init() = 0;
    virtual void update(uint32_t currTime_ms) = 0;
    virtual void render() = 0;

    GamePosition getPosition() const {return m_position;}
    GameVelocity getVelocity() const {return m_velocity;}

    double getSpeed() const {return m_speed;}
    void setSpeed(double speed ){m_speed = speed;}

protected:

    void updateVelocityComponentsFromDirection();
    void checkScreenBoundaries();
    void zeroizeSpeed();

    GamePosition m_position;
    GameVelocity m_velocity;

    double m_speed;
    int m_size;

    Renderer_Ptr m_renderer;
};

#endif // GAMEOBJECT_H
