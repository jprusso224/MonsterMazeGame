#include <random>

#include "Monster.h"
#include "GameConstants.h"

static const uint32_t MONSTER_MOVE_DELAY = 500;

Monster::Monster(Renderer_Ptr renderer)
    : GameEntity(renderer)
{
}

void Monster::init()
{
    if(loadObjectImage())
    {
        qDebug() << "loaded monster image!";
    }

    std::mt19937 rngX;
    std::mt19937 rngY;
    rngX.seed(std::random_device()());
    rngY.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> distX(0,SCREEN_WIDTH);
    std::uniform_int_distribution<std::mt19937::result_type> distY(0,SCREEN_HEIGHT);

    m_position.x = distX(rngX);
    m_position.y = distY(rngY);

    //Initialize timers
    lastEventTime_ms = SDL_GetTicks();
    int gracePeriod_ms = 1000;
    lastFireTime_ms = lastFireTime_ms - gracePeriod_ms;

}

void Monster::update(uint32_t currTime_ms)
{

    if((currTime_ms - lastEventTime_ms) > MONSTER_MOVE_DELAY)
    {
        handleEventTimeout();
        lastEventTime_ms = currTime_ms;
    }

    if((currTime_ms - lastFireTime_ms) > (m_fireRate*1000))
    {
        attack();
        lastFireTime_ms = currTime_ms;
    }

    m_position.x += m_velocity.dx;
    m_position.y += m_velocity.dy;

    checkScreenBoundaries();

    updateProjectiles(currTime_ms);
}

void Monster::render()
{
    SDL_Rect rDest = {m_position.x,m_position.y,0,0};
    SDL_QueryTexture(m_img, NULL, NULL, &rDest.w, &rDest.h);
    SDL_RenderCopy(m_renderer, m_img, NULL, &rDest);

    for(Projectile* p : projectileList)
    {
        if(p != nullptr)
            p->render();
    }
}

void Monster::attack()
{
    qDebug() << "Monster attacked with " << QString::number(m_damage) << " damage!";

    Projectile *p = new Projectile(m_renderer,m_position,m_velocity);
    p->init();
    projectileList.append(p);
}

void Monster::handleEventTimeout()
{

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist5(0,RANDOM_MONSTER_EVENT_COUNT);

    int randomGen = dist5(rng);

    if(randomGen < RandomMonsterEvent::IDLE)
    {
        m_velocity.direction = static_cast<GameDirection>(dist5(rng));

        updateVelocityComponentsFromDirection();
    }
    else
    {
        m_velocity.dx = 0;
        m_velocity.dx = 0;
    }

}
