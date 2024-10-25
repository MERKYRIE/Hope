#include"Hope.hpp"

#include"Pixel.hpp"

namespace NHope::NMouse
{
    SPixel::SPixel()
    {
        FModification = false;
        FX = 0;
        FY = 0;
    }

    SPixel* SPixel::IPreupdate()
    {
        FModification = false;
        FX = 0;
        FY = 0;
        return(this);
    }

    SPixel* SPixel::IPostupdate(std::int32_t const& AX , std::int32_t const& AY)
    {
        FModification = true;
        FX = AX;
        FY = AY;
        return(this);
    }

    SPixel::~SPixel()
    {
    
    }
}