#include "InputHandler.h"

InputHandler::InputHandler()
{
 //no op
}

InputHandler::~InputHandler()
{
 //no op
}

bool InputHandler::init()
{
    return true;
}

ProcessInputType InputHandler::processEvent()
{
    ProcessInputType results = ProcessInputType::NO_EVENT;
    SDL_Event event;

    SDL_PollEvent(&event);
    // check for messages
    switch (event.type)
    {
    case SDL_QUIT:
        results = ProcessInputType::CLOSE_EVENT;
        break;

    // check for keypresses
    case SDL_KEYDOWN:
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            results = ProcessInputType::CLOSE_EVENT;
            break;
        case SDLK_w:
            results = ProcessInputType::UP_ARROW_PRESSED;
            break;
        case SDLK_a:
            results = ProcessInputType::LEFT_ARROW_PRESSED;
            break;
        case SDLK_s:
            results = ProcessInputType::RIGHT_ARROW_PRESSED;
            break;
        case SDLK_d:
            results = ProcessInputType::DOWN_ARROW_PRESSED;
            break;
        default:
            break;
        }
        break;
    }
    case SDL_KEYUP:
    {
        switch(event.key.keysym.sym)
        {
        case SDLK_w:
            results = ProcessInputType::UP_ARROW_RELEASED;
            break;
        case SDLK_a:
            results = ProcessInputType::LEFT_ARROW_RELEASED;
            break;
        case SDLK_s:
            results = ProcessInputType::RIGHT_ARROW_RELEASED;
            break;
        case SDLK_d:
            results = ProcessInputType::DOWN_ARROW_RELEASED;
            break;
        default:
            break;
        }
        break;
    }
    default:

        break;
    } // end switch

    return results;
}


