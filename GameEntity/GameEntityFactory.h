#ifndef GAMEENTITYFACTORY_H
#define GAMEENTITYFACTORY_H

#include <QMap>

#include "EntityLoader.h"
#include "GameTypes.h"
#include "Monster.h"
#include "Player.h"

class GameEntityFactory
{
public:
    GameEntityFactory(Renderer_Ptr renderer, QString entityFile);
    ~GameEntityFactory();

    /*
     * instruct the loader to parse the config file and fill the player
     * and monsters objects.
     */
    bool generateEntities();

    /*
     * returns a nullptr if no player has been created.
     */
    Player* getPlayer(){return m_player;}

    /*
     * returns an empty map if no monsters have been created.
     */
    QMap<int, Monster*> getMonsterMap(){return m_monsterMap;}

private:

    void createNewPlayer(EntityData* data);
    void createNewMonster(EntityData* data);
    void setCommonEntityData(GameEntity* entity ,EntityData* data);

    QMap<int, Monster*> m_monsterMap; /*each monster will have unique ID*/
    Player* m_player;

    Renderer_Ptr m_Renderer; /*All entities require a reference to the renderer*/
    EntityLoader* m_entityLoader;

    int m_monster_UID;

};

#endif // GAMEENTITYFACTORY_H
