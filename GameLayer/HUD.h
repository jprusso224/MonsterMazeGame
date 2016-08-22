#ifndef HUD_MANAGER_H
#define HUD_MANAGER_H

#include "GameLayer.h"

class HUD : public GameLayer
{
    public:
        HUD(SDL_Renderer* renderer);
        virtual ~HUD();

        bool init() override;
        void update(uint32_t currTime_ms) override;
        void draw() override;

    protected:

    private:

};

#endif // HUD_MANAGER_H
