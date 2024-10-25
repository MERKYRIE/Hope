#pragma once

namespace NHope::NMouse
{
    struct SPixel
    {
        bool FModification;
        std::int32_t FX;
        std::int32_t FY;

        SPixel();
        SPixel* IPreupdate();
        SPixel* IPostupdate(std::int32_t const& AX , std::int32_t const& AY);
        ~SPixel();
    };
}