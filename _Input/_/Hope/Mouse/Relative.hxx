#pragma once

namespace NHope::NHope::NMouse
{
    struct SRelative
    {
        bool FModification;
        std::shared_ptr<SPixel> FPixel;
        std::shared_ptr<SRectangle> FRectangle;
        std::shared_ptr<SSquare> FSquare;

        SRelative();
        SRelative* IPreupdate();
        SRelative* IPostupdate(SDL_MouseMotionEvent const& AMotion);
        ~SRelative();
    };
}