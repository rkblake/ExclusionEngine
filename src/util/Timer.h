#ifndef EE_TIMER
#define EE_TIMER

#include <list>

#include <SDL2/SDL.h>

class Timer {
public:
    Timer() {}
    Timer(unsigned int bufferSize, float normalFrameRate);
    ~Timer() {}
    void FrameUpdate();
    unsigned int getElapsedTime();
    float getTimeMultiplier();
    float getFrameRate();
    float getNormalFrameRate();

private:
    std::list<unsigned int> m_times;
    unsigned int m_bufferSize;
    unsigned int m_elapsedTime;
    float m_normalFrameRate;
    unsigned int m_startTime;
    float m_timeMultiplier;
};

#endif
