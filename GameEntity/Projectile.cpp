#include <QDebug>

#include "Projectile.h"

Projectile::Projectile(Renderer_Ptr renderer, GamePosition pos, GameVelocity vel)
    : GameObject(renderer)
{
    m_position = pos;
    m_velocity = vel;
}

void Projectile::init()
{

    m_imgName = QString("Projectile.png");
    m_imgSize = 8; //px

    m_speed = 7;

    if(loadObjectImage())
    {
        qDebug() << "loaded projectile image!";
    }
}

void Projectile::update(uint32_t currTime_ms)
{
    if(m_velocity.direction > GameDirection::UP)
    {
        m_velocity.direction = GameDirection::UP;
    }

    updateVelocityComponentsFromDirection();

    m_position.x += m_velocity.dx;
    m_position.y += m_velocity.dy;
}

void Projectile::render()
{
   // TODO: Use SDL gfx primitives
   // filledCircleRGBA(m_renderer,m_position.x,m_position.y,m_size,0,255,255,255);

    SDL_Rect rDest = {m_position.x,m_position.y,0,0};
    SDL_QueryTexture(m_img, NULL, NULL, &rDest.w, &rDest.h);
    SDL_RenderCopy(m_renderer, m_img, NULL, &rDest);
}

