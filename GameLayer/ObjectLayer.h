#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include "GameEntity/Player.h"
#include <GameLayer/GameLayer.h>
#include "GameEntity/Monster.h"

class ObjectLayer : public GameLayer
{
    public:
        ObjectLayer(Renderer_Ptr renderer);
        virtual ~ObjectLayer();

        bool init() override;
        virtual void processInput(ProcessInputType input);
        void update() override;
        void draw() override;

    protected:

    private:
        Player* m_player;
        QMap<int, Monster*> m_monsterMap;

};

#endif // OBJECTLAYER_H
