#include "GameLayer/HUD.h"
#include "GameConstants.h"

HUD::HUD(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}

HUD::~HUD()
{
    //dtor
}

bool HUD::init()
{
    bool success = true;

    //nothing yet

    return success;
}

void HUD::update()
{
    //Handle business logic
}

void HUD::draw()
{
    int ypos = SCREEN_HEIGHT - (SCREEN_HEIGHT/10);

    SDL_SetRenderDrawColor( m_Renderer, 0x00, 0xcc, 0xf0, 0x99 );
    SDL_Rect fillRect = { 0, ypos , SCREEN_WIDTH, SCREEN_HEIGHT / 10 };
    SDL_RenderFillRect( m_Renderer, &fillRect );

   // SDL_RenderPresent( m_Renderer );
}
