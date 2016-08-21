#ifndef GAMETYPES_H
#define GAMETYPES_H

#define SDL_MAIN_HANDLED
#include <SDL.h>

typedef SDL_Renderer* Renderer_Ptr;
typedef SDL_Surface* Surface_Ptr;

enum class GameDirection
{
    LEFT = 0,
    RIGHT,
    DOWN,
    UP
};

struct GamePosition
{
    GamePosition() : x(0),y(0) {}
    int x;
    int y;
};

struct GameVelocity
{
    GameVelocity() : direction(GameDirection::LEFT),dx(0),dy(0) {}
    GameDirection direction;
    int dx;
    int dy;
};

struct GameMapSize
{
    GameMapSize() : height(0), width(0) {}
    int height;
    int width;
};

#endif // GAMETYPES_H
