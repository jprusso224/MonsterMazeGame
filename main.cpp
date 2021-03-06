
#include <QtGlobal>
#include <QDebug>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "GameEntity/Player.h"
#include "GameEntity/EntityLoader.h"
#include "GameEventTimer.h"
#include "MainWindow.h"
#include "InputHandler.h"

typedef SDL_Window* SDL_WindowPtr;
typedef SDL_Renderer* SDL_RendererPtr;

static const uint32_t FRAME_RATE_MS = 33; //MS per Frame

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    InputHandler* inputHandler = new InputHandler();
    MainWindow* mainWindow = new MainWindow();

    Mix_Music *music = nullptr;
    //Start up SDL and create window


    if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
    {
        qDebug() << QString("SDL could not initialize! SDL_Error: %0").arg(SDL_GetError());
    }
    else
    {
        bool done = false;

        if( !mainWindow->init() )
        {
            qDebug() << QString("Failed to initialize main window!" );
            done = true;
        }

        if(inputHandler->init() == false)
        {
            qDebug() << QString("SDL could not initialize controller, using keyboard/mouse.\n");
        }

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            qDebug() << QString("SDL_image could not initialize! SDL_image Error: %0").arg(IMG_GetError());
        }

        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
             qDebug() << QString("SDL_mixer could not initialize! SDL_mixer Error: %0").arg(Mix_GetError());
        }
                //Load music
        music = Mix_LoadMUS( "Resources\\Db_Phrigian.wav" );
        if( music == NULL )
        {
            qDebug() << QString( "Failed to load music! SDL_mixer Error: %0").arg(Mix_GetError());
        }

        Mix_PlayMusic(music,-1);

        /*Initialize game loop timer at fixed frame rate*/
        GameEventTimer gameUpdateTimer;
        gameUpdateTimer.start(FRAME_RATE_MS);
        uint32_t currentTime_ms = SDL_GetTicks();
        uint32_t elapsedTime_ms = 0;

        /********* THIS IS THE MAIN GAME LOOP ********************/
        qDebug() << QString("Entering main loop! Good luck!");

        while (!done)
        {
            //compute elapsed time
            elapsedTime_ms = SDL_GetTicks() - currentTime_ms;

            //always update the game loop timer!
            gameUpdateTimer.update(elapsedTime_ms);

            //Allow game to continue if game loop timer expires
            if(gameUpdateTimer.isExpired())
            {
                // message processing
                ProcessInputType input = inputHandler->processInput();
                if(input == ProcessInputType::CLOSE_EVENT)
                {
                    done = true;
                    break;
                }

                /*
                 * Pass input to game layers and objects.
                 * TODO: Only pass input to objects that need it. Input Observer?
                 */
                mainWindow->processInput(input);

                //pass elapsed time to game layers and objects
                mainWindow->update(FRAME_RATE_MS);

                //render the game
                mainWindow->draw();

                //restart the game loop timer
                gameUpdateTimer.start(FRAME_RATE_MS);
            }
        }
        /*********END MAIN LOOP***********************************/

    }

    //Clean up
    mainWindow->close();

    SDL_Quit();
    IMG_Quit();

    delete inputHandler;
    delete mainWindow;

    // all is well ;)
    qDebug() << QString("Exited cleanly");
    return 0;

}
