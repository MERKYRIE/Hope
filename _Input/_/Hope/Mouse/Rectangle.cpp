#include"Hope.hpp"

#include"Rectangle.hpp"

namespace NHope::NMouse
{
    SRectangle::SRectangle()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
    }

    SRectangle* SRectangle::IPreupdate()
    {
        FModification = false;
        FX = 0.0;
        FY = 0.0;
        return(this);
    }

    SRectangle* SRectangle::IPostupdate(std::int32_t const& AX , std::int32_t const& AY)
    {
        FModification = true;
        FX = GVideo.IConvertFromPixelToRectangleHorizontal(AX);
        FY = GVideo.IConvertFromPixelToRectangleVertical(AY);
        return(this);
    }

    SRectangle::~SRectangle()
    {
    
    }
}