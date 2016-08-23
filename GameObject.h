#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QString>

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

    // TODO: Make this nominal speed or maximum speed.
    // Otherwise its duplicating velocity info.
    // For now this just indicated the magnitude of speed.
    double getSpeed() const {return m_speed;}
    void setSpeed(double speed ){m_speed = speed;}

    bool isOffScreen();

protected:

    void updateVelocityComponentsFromDirection();
    void checkScreenBoundaries();
    void zeroizeSpeed();
    bool loadObjectImage();

    GamePosition m_position;
    GameVelocity m_velocity;

    double m_speed;
    int m_size;

    QString m_imgName;
    int m_imgSize;

    SDL_Texture* m_img;

    Renderer_Ptr m_renderer;
};

#endif // GAMEOBJECT_H
