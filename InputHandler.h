#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>

#include "GameTypes.h"

class InputHandler
{
    public:

        InputHandler();
        virtual ~InputHandler();

        bool init();

        ProcessInputType processEvent();

};

#endif // INPUTHANDLER_H
