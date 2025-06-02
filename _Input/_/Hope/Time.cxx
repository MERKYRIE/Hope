#include"Hope.hxx"

namespace NHope::NHope
{
    void STime::IUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = SDL_GetTicks();
        FRelative = FAbsolute - FLast;
    }
}