#pragma once

namespace NHope::NMouse
{
    struct SWheel
    {
        bool FModification;
        std::int32_t FState;

        SWheel();
        SWheel* IPreupdate();
        SWheel* IPostupdate(SDL_MouseWheelEvent const& AWheel);
        ~SWheel();
    };
}