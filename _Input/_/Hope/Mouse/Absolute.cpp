#include"Hope.hpp"

#include"Pixel.hpp"
#include"Rectangle.hpp"
#include"Square.hpp"

#include"Absolute.hpp"

namespace NHope::NMouse
{
    SAbsolute::SAbsolute()
    {
        FModification = false;
        FPixel = std::make_shared<SPixel>();
        FRectangle = std::make_shared<SRectangle>();
        FSquare = std::make_shared<SSquare>();
    }

    SAbsolute* SAbsolute::IPreupdate()
    {
        FModification = false;
        return(this);
    }

    SAbsolute* SAbsolute::IPostupdate(SDL_MouseMotionEvent const& AMotion)
    {
        FModification = true;
        FPixel->IPostupdate(AMotion.x , AMotion.y);
        FRectangle->IPostupdate(AMotion.x , AMotion.y);
        FSquare->IPostupdate(AMotion.x , AMotion.y);
        return(this);
    }

    SAbsolute::~SAbsolute()
    {
    
    }
}