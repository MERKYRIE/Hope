#pragma once

namespace NHope::NHope::NMouse
{
    struct SWheel
    {
        bool FModification;
        double FState;

        SWheel();
        SWheel* IPreupdate();
        SWheel* IPostupdate(SDL_MouseWheelEvent const& AWheel);
        ~SWheel();
    };
}