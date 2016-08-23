#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <QString>
#include <QDebug>

#include "GameTypes.h"
#include "GameObject.h"

class GameEntity : public GameObject
{
public:

    GameEntity(Renderer_Ptr renderer);
    virtual ~GameEntity();

    virtual void processInput(ProcessInputType input) = 0;
    virtual void attack() = 0;

    double getHealth() const {return m_health;}
    double getDamage() const {return m_damage;}

    void setHealth(double health){m_health = health;}
    void setDamage(double damage){m_damage = damage;}

    void setImageName(const QString &imgName){m_imgName = imgName;}
    void setImageSize(int size){m_imgSize = size;}

protected:

    QString m_name;

    double m_health;
    double m_damage;

};

#endif // GAMEENTITY_H
