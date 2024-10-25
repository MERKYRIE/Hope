#include"Hope.hpp"

#include"Square.hpp"

namespace NHope::NMouse
{
    SSquare::SSquare()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
    }

    SSquare* SSquare::IPreupdate()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
        return(this);
    }

    SSquare* SSquare::IPostupdate(std::int32_t const& AX , std::int32_t const& AY)
    {
        FModification = true;
        FX = GVideo.IConvertFromPixelToSquare(AX);
        FY = GVideo.IConvertFromPixelToSquare(AY);
        return(this);
    }

    SSquare::~SSquare()
    {
    
    }
}