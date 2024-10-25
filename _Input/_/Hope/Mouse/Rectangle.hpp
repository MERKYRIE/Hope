#pragma once

namespace NHope::NMouse
{
    struct SRectangle
    {
        bool FModification;
        double FX;
        double FY;

        SRectangle();
        SRectangle* IPreupdate();
        SRectangle* IPostupdate(std::int32_t const& AX , std::int32_t const& AY);
        ~SRectangle();
    };
}