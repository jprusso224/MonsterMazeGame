#ifndef MAINMEDIAHANDLER_H
#define MAINMEDIAHANDLER_H

#include <SDL.h>

#include "InputHandler.h"
#include "GameLayer/HUD.h"
#include "GameLayer/ObjectLayer.h"
#include "GameConstants.h"

class MainWindow
{
    public:
        MainWindow();
        virtual ~MainWindow();

        bool init();

        void processInput(ProcessInputType input);

        void update();

        void draw();

        void close();

    protected:

    private:

        SDL_Window* gWindow; /**The window we'll be rendering to*/

        SDL_Renderer* m_Renderer; /**The renderer we'll be windowing to*/

        HUD* m_HUD;
        ObjectLayer* m_objectLayer;

};

#endif // MAINMEDIAHANDLER_H
