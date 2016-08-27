#ifndef GAMETYPES_H
#define GAMETYPES_H

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>

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

    const GamePosition operator+(const GamePosition other) const
    {
        GamePosition result = *(this);
        result.x += other.x;
        result.y += other.y;
        return result;
    }

    const GamePosition operator-(const GamePosition other) const
    {
        GamePosition result = *(this);
        result.x -= other.x;
        result.y -= other.y;
        return result;
    }

    int x;
    int y;
};



struct GameVelocity
{
    GameVelocity() : direction(GameDirection::LEFT),dx(0),dy(0) {}
    GameDirection direction;
    double dx;
    double dy;
};

struct GameMapSize
{
    GameMapSize() : height(0), width(0) {}
    int height;
    int width;
};

struct GameSize
{
    GameSize() : h(0), w(0) {}
    int h;
    int w;
};

enum class ProcessInputType
{
    NO_EVENT = 0,

    UP_ARROW_PRESSED,
    DOWN_ARROW_PRESSED,
    LEFT_ARROW_PRESSED,
    RIGHT_ARROW_PRESSED,
    A_BUTTON_PRESSED,
    B_BUTTON_PRESSED,

    UP_ARROW_RELEASED,
    DOWN_ARROW_RELEASED,
    LEFT_ARROW_RELEASED,
    RIGHT_ARROW_RELEASED,

    CLOSE_EVENT
};


#endif // GAMETYPES_H
