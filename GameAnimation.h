#ifndef GAMEANIMATION_H
#define GAMEANIMATION_H

#include <QList>
#include <SDL.h>

#include "GameEventTimer.h"


enum class AnimationState
{
    NOT_STARTED,
    STARTED,
    FINISHED
};

class GameAnimation
{
public:

    GameAnimation();
    ~GameAnimation();

    AnimationState start();

    AnimationState update(Uint32 elapsedTime_ms);

    SDL_Texture* getCurrentImg() const { return currentImg; }

    /*
     * To create an animation, append a series of images
     * and corresponding interval to display it for
     * before moving on to the next img.
     */
    void appendImg(SDL_Texture* img, Uint32 interval);

private:

    Uint8 size;
    Uint8 currentIdx;

    GameEventTimer* animationTimer;
    QList<SDL_Texture*> imgList;
    QList<Uint32> intervalList;

    SDL_Texture* currentImg;

    AnimationState animationState;

};

#endif // GAMEANIMATION_H
