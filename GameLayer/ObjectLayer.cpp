#include "GameLayer/ObjectLayer.h"
#include "GameConstants.h"
#include "GameTypes.h"
#include "GameEntity/GameEntityFactory.h"
#include "GameEntity/Projectile.h"

ObjectLayer::ObjectLayer(Renderer_Ptr renderer)
{
    m_Renderer = renderer;
}

ObjectLayer::~ObjectLayer()
{
    //dtor
}

bool ObjectLayer::init()
{
    bool success = true;

    GameEntityFactory entityFactory(m_Renderer, QString("Resources\\EntityConfig.xml"));
    entityFactory.generateEntities();

    m_player = entityFactory.getPlayer();
    if(m_player == nullptr)
    {
        success = false;
    }
    else
    {
        m_player->init();
    }

    m_monsterMap = entityFactory.getMonsterMap();
    for(Monster* monster : m_monsterMap)
    {
        monster->init();
    }

    return success;
}

void ObjectLayer::processInput(ProcessInputType input)
{
    m_player->processInput(input);
}

void ObjectLayer::update(uint32_t elapsedTime_ms)
{

    QList<int> deathMarks;

    for(Monster* monster : m_monsterMap)
    {
        /*
         * Pass each monster a const reference to the player.
         * This is necessary so the monsters can attack the player.
         */
        monster->setPlayer(m_player);

        monster->update(elapsedTime_ms);

        if(monster->getHealthState() == EntityHealthState::DEAD)
        {
            //mark for death
            deathMarks.append(m_monsterMap.key(monster));
        }
    }

    //Kill monsters marked for death.
    for(int mark : deathMarks)
    {
        m_monsterMap.remove(mark);
    }

    m_player->update(elapsedTime_ms);

    checkProjectileHits();

}

void ObjectLayer::draw()
{
    m_player->render();
    for(Monster* monster : m_monsterMap)
    {
        monster->render();
    }

}

void ObjectLayer::checkProjectileHits()
{

    //Check for collisions. Need to get a reference to the
    //players list of projectiles. For each active projectile,
    //check to see if it has hit a monster. If so, remove/delete
    //the projectile and decrement the monsters health.
    //TODO: Animate the monster being hit by blitting the texture.

    //START PLAYER PROJECTILE TO MONSTER COLLISIONS
    QList<Projectile*> playerProjectiles = m_player->getProjectiles();
    QList<int> removeIdxList;
    for(Projectile* p : playerProjectiles)
    {
        for(Monster* m : m_monsterMap)
        {
            //Will do calculations here now but move later
            //Assume projectile is particle and offset position
            //to center. pOrig is top left corner.
            int pSize = p->getSize();
            GamePosition pOrig = p->getPosition();

            GamePosition pCenteredPos;
            pCenteredPos.x = pOrig.x + (pSize/2);
            pCenteredPos.y = pOrig.y + (pSize/2);

            GamePosition mPos = m->getPosition();
            GameSize hitbox;
            hitbox.h = m->getSize();
            hitbox.w = m->getSize();

            //if is in hitbox
            if((pCenteredPos.x > mPos.x && pCenteredPos.x < (mPos.x + hitbox.w)) && (pCenteredPos.y > mPos.y && pCenteredPos.y < (mPos.y + hitbox.w)))
            {
                //hit!!!!!
                qDebug() << "Monster Hit!!!";
                m->processHit(m_player->getDamage());
                removeIdxList.append(playerProjectiles.indexOf(p));
                break;//one monster hit per projectile.

            }
        }
    }

    //Remove the projectiles that were hits!
    if(!removeIdxList.isEmpty())
    {
        m_player->removeProjectiles(removeIdxList);
    }
    //END PLAYER PROJECTILE TO MONSTER COLLISIONS

    //START MONSTER PROJECTILE TO PLAYER COLLISIONS
    for(Monster* m : m_monsterMap)
    {
        QList<Projectile*> monsterProjectiles = m->getProjectiles();
        QList<int> removeIdxList;
        for(Projectile* p : monsterProjectiles)
        {
            //Will do calculations here now but move later
            //Assume projectile is particle and offset position
            //to center. pOrig is top left corner.
            int pSize = p->getSize();
            GamePosition pOrig = p->getPosition();

            GamePosition pCenteredPos;
            pCenteredPos.x = pOrig.x + (pSize/2);
            pCenteredPos.y = pOrig.y + (pSize/2);

            GamePosition mPos = m_player->getPosition();
            GameSize hitbox;
            hitbox.h = m->getSize();
            hitbox.w = m->getSize();

            //if is in hitbox
            if((pCenteredPos.x > mPos.x && pCenteredPos.x < (mPos.x + hitbox.w)) && (pCenteredPos.y > mPos.y && pCenteredPos.y < (mPos.y + hitbox.w)))
            {
                //hit!!!!!
                qDebug() << "Player Hit!!!";
                m_player->processHit(m->getDamage());
                removeIdxList.append(monsterProjectiles.indexOf(p));

            }
        }

        //Remove the projectiles that were hits!
        if(!removeIdxList.isEmpty())
        {
            m->removeProjectiles(removeIdxList);
        }
    }
    //END MONSTER PROJECTILE TO PLAYER COLLISIONS
}
