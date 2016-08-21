#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <GameTypes.h>
#include <QString>

class GameEntity
{
public:
    GameEntity(){}
    GameEntity(Renderer_Ptr renderer);
    virtual ~GameEntity();

  //  virtual void update() = 0;
  //  virtual void render() = 0;

    GamePosition getPosition() const {return m_position;}
    GameVelocity getVelocity() const {return m_velocity;}

    int getHealth() const {return m_health;}
    int getDamage() const {return m_damage;}
    int getSpeed() const {return m_speed;}

    void setHealth(int health){m_health = health;}
    void setDamage(int damage){m_damage = damage;}
    void setSpeed(int speed ){m_speed = speed;}

protected:

    QString m_name;

    Renderer_Ptr m_renderer;
    Surface_Ptr m_surface;

    GamePosition m_position;
    GameVelocity m_velocity;

    int m_health;
    int m_damage;
    int m_speed;

};

#endif // GAMEENTITY_H
