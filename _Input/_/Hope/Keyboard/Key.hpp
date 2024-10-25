#pragma once

namespace NHope::NKeyboard
{
    struct SKey
    {
        bool FModification;
        std::string FState;

        SKey();
        void IPreupdate();
        void IPostupdate(SDL_Event const& AEvent);
        ~SKey();
    };
}