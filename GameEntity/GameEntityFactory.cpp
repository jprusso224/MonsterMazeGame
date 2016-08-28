#include "GameEntityFactory.h"

GameEntityFactory::GameEntityFactory(Renderer_Ptr renderer, QString entityFile)
    : m_Renderer(renderer),
      m_entityLoader(new EntityLoader(entityFile)),
      m_monster_UID(0)
{
}

GameEntityFactory::~GameEntityFactory(){}

bool GameEntityFactory::generateEntities()
{
    bool success = true;
    QList<EntityData*> rawEntityList;

    if(m_entityLoader->loadEntities())
    {
        rawEntityList = m_entityLoader->getEntities();

        for(EntityData* data : rawEntityList)
        {
            if(data->type.compare(QString("Player")) == 0)
            {
                qDebug() << "creating new player!";
                createNewPlayer(data);
            }
            if(data->type.compare(QString("Monster")) == 0)
            {
                qDebug() << "creating new monster!";
                createNewMonster(data);
            }
        }
    }
    else
    {
        qDebug() << "failed to load entities";
        success = false;
    }

    return success;
}

void GameEntityFactory::createNewPlayer(EntityData* data)
{
    m_player = new Player(m_Renderer);
    setCommonEntityData(m_player, data);

}

void GameEntityFactory::createNewMonster(EntityData* data)
{
    Monster* monster = new Monster(m_Renderer);
    setCommonEntityData(monster, data);

    monster->setFireRate(data->firerate);

    //insert monster and increment unique monster ID
    m_monsterMap.insert(m_monster_UID, monster);
    m_monster_UID++;
}

void GameEntityFactory::setCommonEntityData(GameEntity* entity ,EntityData* data)
{
    entity->setHealth(data->health);
    entity->setSpeed(data->speed);
    entity->setDamage(data->damage);
    entity->setImageName(data->imgName);
    entity->setImageSize(data->imgSize);
    entity->setHitImgName(data->imgHitName);
}


