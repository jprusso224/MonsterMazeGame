#include "Monster.h"

Monster::Monster(Renderer_Ptr renderer)
    : GameEntity(renderer)
{
}

void Monster::init()
{
    if(loadEntityImage())
    {
        qDebug() << "loaded monster image!";
    }
}

void Monster::render()
{
    SDL_Rect rDest = {3,400,0,0};
    SDL_QueryTexture(m_img, NULL, NULL, &rDest.w, &rDest.h);
    SDL_RenderCopy(m_renderer, m_img, NULL, &rDest);
}
