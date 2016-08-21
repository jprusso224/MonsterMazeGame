#include "Player.h"

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

void Player::update()
{
    //randomly pick pos
}

void Player::render()
{
    SDL_Rect rDest = {100,100,0,0};
    SDL_QueryTexture(m_img, NULL, NULL, &rDest.w, &rDest.h);
    SDL_RenderCopy(m_renderer, m_img, NULL, &rDest);
}
