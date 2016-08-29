#include "GameEntity.h"
#include "GameConstants.h"

GameEntity::GameEntity(Renderer_Ptr renderer)
    : GameObject(renderer),
      hitAnimation(new GameAnimation()),
      hitState(EntityHitState::NOT_HIT),
      healthState(EntityHealthState::ALIVE)

{
}

GameEntity::~GameEntity(){}

bool GameEntity::loadHitImage()
{
    QString fullPath = QString("Resources\\" + m_hitImgName);
    m_hitImg = IMG_LoadTexture(m_renderer,fullPath.toStdString().c_str());

    if(m_hitImg == nullptr)
        return false;
    return true;
}


void GameEntity::processHit(int damage)
{
    //set this back to not hit once hit animation is finished.
    hitState = EntityHitState::HIT_BY_PROJECTILE;

    m_health -= damage;

    if(m_health < 0)
    {
        qDebug() << m_name << " was killed!";
        healthState = EntityHealthState::DEAD;
    }

    if(hitAnimation->start() != AnimationState::STARTED)
    {
        qDebug() << "Failed to start hit animation!!!";
    }
}

void GameEntity::updateHitState(uint32_t elapsedTime_ms)
{
    if(hitState == EntityHitState::HIT_BY_PROJECTILE)
    {
        if(hitAnimation->update(elapsedTime_ms) == AnimationState::FINISHED)
        {
            hitState = EntityHitState::NOT_HIT;
        }

        m_img = hitAnimation->getCurrentImg();
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
        if(idx < projectileList.size())
        {
            Projectile* pRemove = projectileList.at(idx); //BUG HERE
            projectileList.removeAt(idx);
            delete pRemove;
        }
    }
}

