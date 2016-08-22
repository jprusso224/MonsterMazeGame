#include "Player.h"
#include "Projectile.h"

Player::Player(Renderer_Ptr renderer)
    : GameEntity(renderer)
{
}

void Player::init()
{
    if(loadEntityImage())
    {
        qDebug() << "loaded player image!";
    }
}

void Player::processInput(ProcessInputType input)
{
    switch(input)
    {

    /****START ARROW PRESSED INPUT******************/
    case ProcessInputType::DOWN_ARROW_PRESSED:
        m_velocity.direction = GameDirection::DOWN;
        updateVelocityComponentsFromDirection();
    break;
    case ProcessInputType::UP_ARROW_PRESSED:
        m_velocity.direction = GameDirection::UP;
        updateVelocityComponentsFromDirection();
    break;
    case ProcessInputType::LEFT_ARROW_PRESSED:
        m_velocity.direction = GameDirection::LEFT;
        updateVelocityComponentsFromDirection();
    break;
    case ProcessInputType::RIGHT_ARROW_PRESSED:
        m_velocity.direction = GameDirection::RIGHT;
        updateVelocityComponentsFromDirection();
    break;
    /****END ARROW PRESSED INPUT*********************/

    /****START ARROW RELEASED INPUT******************/
    case ProcessInputType::DOWN_ARROW_RELEASED:
        if(m_velocity.direction == GameDirection::DOWN)
            zeroizeSpeed();
    break;
    case ProcessInputType::UP_ARROW_RELEASED:
        if(m_velocity.direction == GameDirection::UP)
            zeroizeSpeed();
    break;
    case ProcessInputType::LEFT_ARROW_RELEASED:
        if(m_velocity.direction == GameDirection::LEFT)
            zeroizeSpeed();
    break;
    case ProcessInputType::RIGHT_ARROW_RELEASED:
        if(m_velocity.direction == GameDirection::RIGHT)
            zeroizeSpeed();
    break;
    /****END ARROW RELEASED INPUT********************/

    /****ACTION INPUT********************************/
    case ProcessInputType::A_BUTTON_PRESSED:
        attack();
    break;

    }
}

void Player::update(uint32_t currTime_ms)
{
    Q_UNUSED(currTime_ms)

    m_position.x += m_velocity.dx;
    m_position.y += m_velocity.dy;

    checkScreenBoundaries();
}

void Player::render()
{
    SDL_Rect rDest = {m_position.x,m_position.y,0,0};
    SDL_QueryTexture(m_img, NULL, NULL, &rDest.w, &rDest.h);
    SDL_RenderCopy(m_renderer, m_img, NULL, &rDest);
}

void Player::attack()
{
    qDebug() << "Player attacked with " << QString::number(m_damage) << " damage!";

    Projectile * projectile = new Projectile(m_renderer,m_position,m_velocity);

}
