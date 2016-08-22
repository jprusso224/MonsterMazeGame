#include "GameLayer/ObjectLayer.h"
#include "GameConstants.h"
#include "GameEntity/GameEntityFactory.h"

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

}

void ObjectLayer::draw()
{
    m_player->render();
    for(Monster* monster : m_monsterMap)
    {
        monster->render();
    }

}

