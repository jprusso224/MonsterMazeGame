#include "GameObject.h"
#include "GameConstants.h"

GameObject::GameObject(Renderer_Ptr renderer) : m_renderer(renderer)
{
}

void GameObject::updateVelocityComponentsFromDirection()
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

void GameObject::checkScreenBoundaries()
{
    if(m_position.x < 0)
    {
        m_velocity.dx = 0;
        m_position.x = 0;
    }
    else if(m_position.x > (SCREEN_WIDTH - m_size))
    {
        m_velocity.dx = 0;
        m_position.x = SCREEN_WIDTH - m_size;
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
    else if(m_position.y > (SCREEN_HEIGHT - m_size))
    {
        m_velocity.dy = 0;
        m_position.y = SCREEN_HEIGHT - m_size;
    }
    else
    {
        //no op
    }
}

void GameObject::zeroizeSpeed()
{
    m_velocity.dx = 0;
    m_velocity.dy = 0;
}
