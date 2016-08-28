#include "GameAnimation.h"

GameAnimation::GameAnimation()
{
    animationState = AnimationState::NOT_STARTED;
}
GameAnimation::~GameAnimation()
{
    intervalList.clear();
    imgList.clear();
}

AnimationState GameAnimation::start()
{
    animationTimer = new GameEventTimer();
    currentIdx = 0;
    size = imgList.size();

    if(size > 0)
    {
        currentImg = imgList.at(currentIdx);
        animationTimer->start(intervalList.at(currentIdx));
        animationState = AnimationState::STARTED;
    }

    return animationState;
}


AnimationState GameAnimation::update(Uint32 elapsedTime_ms)
{

    animationTimer->update(elapsedTime_ms);
    if(animationTimer->isExpired())
    {
        currentIdx++;
        if(currentIdx == size)
        {
             currentIdx = 0;
             animationState = AnimationState::FINISHED;
             return animationState;
        }
        currentImg = imgList.at(currentIdx);
    }

    return animationState;
}

void GameAnimation::appendImg(SDL_Texture* img, Uint32 interval)
{
    imgList.append(img);
    intervalList.append(interval);
}
