#pragma once

namespace NHope::NHope::NKeyboard
{
    struct SKey
    {
        bool FModification;
        std::string FState;

        SKey();
        void IPreupdate();
        void IPostupdate(SDL_KeyboardEvent const& AEvent);
        ~SKey();
    };
}