#pragma once

namespace NHope
{
    namespace NMouse
    {
        struct SAbsolute;
        struct SButton;
        struct SCursor;
        struct SPixel;
        struct SRectangle;
        struct SRelative;
        struct SSquare;
        struct SWheel;
    }

    inline struct SMouse
    {
        std::unordered_map<std::string , std::shared_ptr<NMouse::SButton>> FButtons;
        std::unordered_map<std::int64_t , std::string> FButtonsAdaptors;

        std::shared_ptr<NMouse::SCursor> FCursor;

        std::shared_ptr<NMouse::SWheel> FWheel;

        SMouse();
        void IPreupdate();
        void IPostupdate(SDL_Event const& AEvent);
        ~SMouse();
    }
    GMouse;
}