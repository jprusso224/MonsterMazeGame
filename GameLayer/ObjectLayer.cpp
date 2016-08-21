#include "GameLayer/ObjectLayer.h"
#include "GameConstants.h"
ObjectLayer::ObjectLayer(SDL_Renderer* renderer)
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

    //nothing yet
    //success = m_player->init();

    return success;
}

void ObjectLayer::update()
{
    //Handle business logic
    //m_player->update();

}

void ObjectLayer::draw()
{
    //for now, draw player (just a triangle
    //m_player->draw();


}

