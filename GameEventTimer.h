#ifndef GAMEEVENTTIMER_H
#define GAMEEVENTTIMER_H
#include <stdint.h>

class GameEventTimer
{
public:
    GameEventTimer(){}
    void start(const uint32_t timeToWait_ms)
    {
        m_runningTime = 0;
        m_timeToWait = timeToWait_ms;
    }
    void update(const uint32_t elapsedTime_ms)
    {
        m_runningTime+=elapsedTime_ms;
    }
    bool isExpired()
    {
        return (m_runningTime > m_timeToWait) ? true : false;
    }

private:

    uint32_t m_timeToWait;
    uint32_t m_runningTime;

};

#endif // GAMEEVENTTIMER_H
