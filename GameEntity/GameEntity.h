#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <QString>
#include <QDebug>

#include "GameTypes.h"

class GameEntity
{
public:
    GameEntity(){}
    GameEntity(Renderer_Ptr renderer);
    virtual ~GameEntity();

    virtual void init() = 0;
    virtual void processInput(ProcessInputType input) = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual void attack() = 0;

    GamePosition getPosition() const {return m_position;}
    GameVelocity getVelocity() const {return m_velocity;}

    double getHealth() const {return m_health;}
    double getDamage() const {return m_damage;}
    double getSpeed() const {return m_speed;}

    void setHealth(double health){m_health = health;}
    void setDamage(double damage){m_damage = damage;}
    void setSpeed(double speed ){m_speed = speed;}
    void setImageName(const QString &imgName){m_imgName = imgName;}
    void setImageSize(int size){m_imgSize = size;}

protected:

    bool loadEntityImage();

    void updateVelocityComponentsFromDirection();
    void checkScreenBoundaries();
    void zeroizeSpeed();

    QString m_name;

    Renderer_Ptr m_renderer;
    Surface_Ptr m_surface;

    GamePosition m_position;
    GameVelocity m_velocity;

    double m_health;
    double m_damage;
    double m_speed;

    QString m_imgName;
    int m_imgSize;

    SDL_Texture* m_img;

};

#endif // GAMEENTITY_H
