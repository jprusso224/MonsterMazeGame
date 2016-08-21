#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include <GameLayer/GameLayer.h>


class ObjectLayer : public GameLayer
{
    public:
        ObjectLayer(SDL_Renderer* renderer);
        virtual ~ObjectLayer();

        bool init() override;
        void update() override;
        void draw() override;

    protected:

    private:
};

#endif // OBJECTLAYER_H
