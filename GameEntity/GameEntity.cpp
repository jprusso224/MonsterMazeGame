#include "GameEntity.h"
#include "GameConstants.h"

GameEntity::GameEntity(Renderer_Ptr renderer) : m_renderer(renderer)
{

}
GameEntity::~GameEntity(){}

bool GameEntity::loadEntityImage()
{
    QString fullPath = QString("Resources\\" + m_imgName);
    m_img = IMG_LoadTexture(m_renderer,fullPath.toStdString().c_str());
    if(m_img == nullptr)
        return false;
    return true;
}

void GameEntity::updateVelocityComponentsFromDirection()
{
    switch(m_velocity.direction)
    {
    case GameDirection::LEFT:
        m_velocity.dx = -m_speed;
        m_velocity.dy = 0;
        break;
    case GameDirection::RIGHT:
        m_velocity.dx = m_speed;
        m_velocity.dy = 0;
        break;
    case GameDirection::DOWN:
        m_velocity.dx = 0;
        m_velocity.dy = m_speed;
        break;
    case GameDirection::UP:
        m_velocity.dx = 0;
        m_velocity.dy = -m_speed;
        break;
    default:
        break;
    }
}

void GameEntity::checkScreenBoundaries()
{
    if(m_position.x < 0)
    {
        m_velocity.dx = 0;
        m_position.x = 0;
    }
    else if(m_position.x > (SCREEN_WIDTH - m_imgSize))
    {
        m_velocity.dx = 0;
        m_position.x = SCREEN_WIDTH - m_imgSize;
    }
    else
    {
        //no op
    }

    if(m_position.y < 0)
    {
        m_velocity.dy = 0;
        m_position.y = 0;
    }
    else if(m_position.y > (SCREEN_HEIGHT - m_imgSize))
    {
        m_velocity.dy = 0;
        m_position.y = SCREEN_HEIGHT - m_imgSize;
    }
    else
    {
        //no op
    }
}

void GameEntity::zeroizeSpeed()
{
    m_velocity.dx = 0;
    m_velocity.dy = 0;
}
