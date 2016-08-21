
#include <QDebug>
#include "MainWindow.h"

MainWindow::MainWindow()
{
    //ctor
}

MainWindow::~MainWindow()
{

    delete m_objectLayer;

}

bool MainWindow::init()
{
    //Initialization flag
    bool success = true;

    //Create window
    gWindow = SDL_CreateWindow( "Monster Hunter Maze Master", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        qDebug() << QString("Window could not be created! SDL_Error: %0").arg(SDL_GetError());
        success = false;
    }
    else
    {

        m_Renderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC  );
        if(m_Renderer == nullptr)
        {
            qDebug() << QString("Failed to create renderer");
            success = false;
        }
        else
        {
            SDL_SetRenderDrawBlendMode(m_Renderer,SDL_BLENDMODE_BLEND);

            m_objectLayer = new ObjectLayer(m_Renderer);
            if(m_objectLayer->init() == false)
            {
                qDebug() << QString("Object layer failed to init.");
                success = false;
            }

        }

    }

    return success;
}

void MainWindow::processInput(ProcessInputType input)
{
    m_objectLayer->processInput(input);
}

void MainWindow::update()
{
    m_objectLayer->update();
}

void MainWindow::draw()
{
    m_objectLayer->draw();

    SDL_RenderPresent( m_Renderer );
    SDL_RenderClear( m_Renderer );
}

void MainWindow::close()
{

    SDL_DestroyRenderer(m_Renderer);

    //Destroy window
    SDL_DestroyWindow( gWindow );

}
