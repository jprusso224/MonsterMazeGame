#include "GameEntity.h"
#include "GameConstants.h"

GameEntity::GameEntity(Renderer_Ptr renderer)
    : GameObject(renderer)
{
}

GameEntity::~GameEntity(){}

void GameEntity::processHit(int damage)
{
    m_health -= damage;

    if(m_health < 0)
    {
        qDebug() << m_name << " was killed!";
    }
}

void GameEntity::updateProjectiles(uint32_t currTime_ms)
{
    QList<uint16_t> removalList;

    for(Projectile* p : projectileList)
    {
        if(p != nullptr)
        {
            p->update(currTime_ms);

            if(p->isOffScreen())
            {
                removalList.append(projectileList.indexOf(p));
            }
        }
    }

    for(uint16_t idx : removalList)
    {
        Projectile* pOffScreen = projectileList.at(idx);
        projectileList.removeAt(idx);
        delete pOffScreen;
    }
}

void GameEntity::removeProjectiles(QList<int> projectileIdxToRemove)
{
    //Remove AND delete projectiles when they are no longer in use.
    for(int idx : projectileIdxToRemove)
    {
        Projectile* pRemove = projectileList.at(idx);
        projectileList.removeAt(idx);
        delete pRemove;
    }
}

