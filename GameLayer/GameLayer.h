#ifndef GAMELAYER_H
#define GAMELAYER_H

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "GameTypes.h"

class GameLayer
{

    public:

        GameLayer(){}
        virtual ~GameLayer(){}

        virtual bool init() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:

        Renderer_Ptr m_Renderer;

};

#endif // GAMELAYER_H
