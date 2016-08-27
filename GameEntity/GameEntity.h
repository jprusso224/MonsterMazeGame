#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <QString>
#include <QDebug>

#include "GameTypes.h"
#include "GameObject.h"
#include "Projectile.h"

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

    /*
     * Need to return by reference so the object layer can remove them
     * upon collision. Don't forget to delete!
     */
    QList<Projectile*> getProjectiles(){return projectileList;}
    void removeProjectiles(QList<int> projectileIdxToRemove);

    void processHit(int damage);


protected:

    void updateProjectiles(uint32_t currTime_ms);

    QString m_name;

    double m_health;
    double m_damage;

    /*
     * TODO: Consider making this an object pool since the projectiles will be
     * allocated and de-allocated very often. Could be a fixed list of
     * 100 or so projectile objects.
     */
    QList<Projectile*> projectileList;

};

#endif // GAMEENTITY_H
