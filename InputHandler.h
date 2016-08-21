#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>

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

class InputHandler
{
    public:

        InputHandler();
        virtual ~InputHandler();

        bool init();

        ProcessInputType processEvent();


};

#endif // INPUTHANDLER_H
