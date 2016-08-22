#include "Projectile.h"
#include <SDL2_gfxPrimitives.h>

Projectile::Projectile(Renderer_Ptr renderer, GamePosition pos, GameVelocity vel)
    : GameObject(renderer)
{
    m_position = pos;
    m_velocity = vel;
}

void Projectile::init()
{
    m_size = 5; //lets call it radius
}

void Projectile::update(uint32_t currTime_ms)
{
    updateVelocityComponentsFromDirection();

    m_position.x += m_velocity.dx;
    m_position.y += m_velocity.dy;
}

void Projectile::render()
{
   // filledCircleRGBA(m_renderer,m_position.x,m_position.y,m_size,0,255,255,255);
}

