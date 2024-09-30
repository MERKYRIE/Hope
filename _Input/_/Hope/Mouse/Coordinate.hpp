#pragma once

namespace NHope::NMouse::NCoordinate
{
    struct SCoordinate
    {
        std::int32_t FPixel;
        double FRectangle;
        double FSquare;

        SCoordinate();

        std::int32_t const& IPixel();

        SCoordinate* IPixel(std::int32_t const& AValue);

        SCoordinate* IUpdate(SDL_Event const& AEvent);

        ~SCoordinate();
    };
}