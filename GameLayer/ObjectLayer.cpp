#include "GameLayer/ObjectLayer.h"
#include "GameConstants.h"
#include "GameTypes.h"
#include "GameEntity/GameEntityFactory.h"
#include "GameEntity/Projectile.h"

ObjectLayer::ObjectLayer(Renderer_Ptr renderer)
{
    m_Renderer = renderer;
    //m_player = new Player(renderer,SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
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

void ObjectLayer::update(uint32_t currTime_ms)
{

    for(Monster* monster : m_monsterMap)
    {
        monster->update(currTime_ms);
    }

    m_player->update(currTime_ms);

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
}
