#include"Hope.hpp"

#include"Coordinate.hpp"

namespace NHope::NMouse::NCoordinate
{
    SCoordinate::SCoordinate()
    {
        FPixel = 0;
        FRectangle = 0.0;
        FSquare = 0.0;
    }

    std::int32_t const& SCoordinate::IPixel()
    {
        return(FPixel);
    }

    SCoordinate* SCoordinate::IPixel(std::int32_t const& AValue)
    {
        FPixel = AValue;
        return(this);
    }

    SCoordinate* SCoordinate::IUpdate(SDL_Event const& AEvent)
    {
        switch(AEvent.type)
        {
            case(SDL_MOUSEBUTTONDOWN):
                FStates["Pressed"] = true;
                FStates["Held"] = true;
                FStates["Released"] = false;
            break;
            case(SDL_MOUSEBUTTONUP):
                FStates["Pressed"] = false;
                FStates["Held"] = false;
                FStates["Released"] = true;
            break;
        }
        return(this);
    }

    SCoordinate::~SCoordinate()
    {
    
    }
}