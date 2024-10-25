#pragma once

namespace NHope::NMouse
{
    struct SSquare
    {
        bool FModification;
        double FX;
        double FY;

        SSquare();
        SSquare* IPreupdate();
        SSquare* IPostupdate(std::int32_t const& AX , std::int32_t const& AY);
        ~SSquare();
    };
}