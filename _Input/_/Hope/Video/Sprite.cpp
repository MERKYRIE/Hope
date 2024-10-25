#include"Hope.hpp"

#include"Image.hpp"
#include"Sprite.hpp"

namespace NHope::NVideo
{
    SSprite::SSprite()
    {
        FImage = nullptr;
        FSource = {};
        FDestination = {};
    }

    void SSprite::ILoad(SImage* AImage)
    {
        FImage = AImage;
        FSource.w = FImage->IWidth();
        FSource.h = FImage->IHeight();
    }

    std::int32_t SSprite::IAccessSourceX()
    {
        return(FSource.x);
    }

    std::int32_t SSprite::IAccessSourceY()
    {
        return(FSource.y);
    }

    std::int32_t SSprite::IAccessSourceWidth()
    {
        return(FSource.w);
    }

    std::int32_t SSprite::IAccessSourceHeight()
    {
        return(FSource.h);
    }

    void SSprite::IAccessSourceXAbsolute(std::int32_t AX)
    {
        FSource.x = AX;
    }

    void SSprite::IAccessSourceYAbsolute(std::int32_t AY)
    {
        FSource.y = AY;
    }

    void SSprite::IAccessSourceWidthAbsolute(std::int32_t AWidth)
    {
        FSource.w = AWidth;
    }

    void SSprite::IAccessSourceHeightAbsolute(std::int32_t AHeight)
    {
        FSource.h = AHeight;
    }

    void SSprite::IAccessSourceXRelative(std::int32_t AX)
    {
        FSource.x += AX;
    }

    void SSprite::IAccessSourceYRelative(std::int32_t AY)
    {
        FSource.y += AY;
    }

    void SSprite::IAccessSourceWidthRelative(std::int32_t AWidth)
    {
        FSource.w += AWidth;
    }

    void SSprite::IAccessSourceHeightRelative(std::int32_t AHeight)
    {
        FSource.h += AHeight;
    }

    double SSprite::IAccessSourceXRectangle()
    {
        return(static_cast<double>(FSource.x) / static_cast<double>(FImage->IWidth()));
    }

    double SSprite::IAccessSourceYRectangle()
    {
        return(static_cast<double>(FSource.y) / static_cast<double>(FImage->IHeight()));
    }

    double SSprite::IAccessSourceWidthRectangle()
    {
        return(static_cast<double>(FSource.w) / static_cast<double>(FImage->IWidth()));
    }

    double SSprite::IAccessSourceHeightRectangle()
    {
        return(static_cast<double>(FSource.h) / static_cast<double>(FImage->IHeight()));
    }

    void SSprite::IAccessSourceXRectangleAbsolute(double AX)
    {
        FSource.x = static_cast<std::int32_t>(FImage->IWidth() * AX);
    }

    void SSprite::IAccessSourceYRectangleAbsolute(double AY)
    {
        FSource.y = static_cast<std::int32_t>(FImage->IHeight() * AY);
    }

    void SSprite::IAccessSourceWidthRectangleAbsolute(double AWidth)
    {
        FSource.w = static_cast<std::int32_t>(FImage->IWidth() * AWidth);
    }

    void SSprite::IAccessSourceHeightRectangleAbsolute(double AHeight)
    {
        FSource.h = static_cast<std::int32_t>(FImage->IHeight() * AHeight);
    }

    void SSprite::IAccessSourceXRectangleRelative(double AX)
    {
        FSource.x += static_cast<std::int32_t>(FImage->IWidth() * AX);
    }

    void SSprite::IAccessSourceYRectangleRelative(double AY)
    {
        FSource.y += static_cast<std::int32_t>(FImage->IHeight() * AY);
    }

    void SSprite::IAccessSourceWidthRectangleRelative(double AWidth)
    {
        FSource.w += static_cast<std::int32_t>(FImage->IWidth() * AWidth);
    }

    void SSprite::IAccessSourceHeightRectangleRelative(double AHeight)
    {
        FSource.h += static_cast<std::int32_t>(FImage->IHeight() * AHeight);
    }

    double SSprite::IAccessSourceXSquare()
    {
        return(static_cast<double>(FSource.x) / static_cast<double>(FImage->IMinimum()));
    }

    double SSprite::IAccessSourceYSquare()
    {
        return(static_cast<double>(FSource.y) / static_cast<double>(FImage->IMinimum()));
    }

    double SSprite::IAccessSourceWidthSquare()
    {
        return(static_cast<double>(FSource.w) / static_cast<double>(FImage->IMinimum()));
    }

    double SSprite::IAccessSourceHeightSquare()
    {
        return(static_cast<double>(FSource.h) / static_cast<double>(FImage->IMinimum()));
    }

    void SSprite::IAccessSourceXSquareAbsolute(double AX)
    {
        FSource.x = static_cast<std::int32_t>(FImage->IMinimum() * AX);
    }

    void SSprite::IAccessSourceYSquareAbsolute(double AY)
    {
        FSource.y = static_cast<std::int32_t>(FImage->IMinimum() * AY);
    }

    void SSprite::IAccessSourceWidthSquareAbsolute(double AWidth)
    {
        FSource.w = static_cast<std::int32_t>(FImage->IMinimum() * AWidth);
    }

    void SSprite::IAccessSourceHeightSquareAbsolute(double AHeight)
    {
        FSource.h = static_cast<std::int32_t>(FImage->IMinimum() * AHeight);
    }

    void SSprite::IAccessSourceXSquareRelative(double AX)
    {
        FSource.x += static_cast<std::int32_t>(FImage->IMinimum() * AX);
    }

    void SSprite::IAccessSourceYSquareRelative(double AY)
    {
        FSource.y += static_cast<std::int32_t>(FImage->IMinimum() * AY);
    }

    void SSprite::IAccessSourceWidthSquareRelative(double AWidth)
    {
        FSource.w += static_cast<std::int32_t>(FImage->IMinimum() * AWidth);
    }
    void SSprite::IAccessSourceHeightSquareRelative(double AHeight)
    {
        FSource.h += static_cast<std::int32_t>(FImage->IMinimum() * AHeight);
    }

    std::int32_t SSprite::IAccessDestinationX()
    {
        return(FDestination.x);
    }

    std::int32_t SSprite::IAccessDestinationY()
    {
        return(FDestination.y);
    }

    std::int32_t SSprite::IAccessDestinationWidth()
    {
        return(FDestination.w);
    }

    std::int32_t SSprite::IAccessDestinationHeight()
    {
        return(FDestination.h);
    }

    void SSprite::IAccessDestinationXAbsolute(std::int32_t AX)
    {
        FDestination.x = AX;
    }

    void SSprite::IAccessDestinationYAbsolute(std::int32_t AY)
    {
        FDestination.y = AY;
    }

    void SSprite::IAccessDestinationWidthAbsolute(std::int32_t AWidth)
    {
        FDestination.w = AWidth;
    }

    void SSprite::IAccessDestinationHeightAbsolute(std::int32_t AHeight)
    {
        FDestination.h = AHeight;
    }

    void SSprite::IAccessDestinationXRelative(std::int32_t AX)
    {
        FDestination.x += AX;
    }

    void SSprite::IAccessDestinationYRelative(std::int32_t AY)
    {
        FDestination.y += AY;
    }

    void SSprite::IAccessDestinationWidthRelative(std::int32_t AWidth)
    {
        FDestination.w += AWidth;
    }

    void SSprite::IAccessDestinationHeightRelative(std::int32_t AHeight)
    {
        FDestination.h += AHeight;
    }

    double SSprite::IAccessDestinationXRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleHorizontal(FDestination.x));
    }

    double SSprite::IAccessDestinationYRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleVertical(FDestination.y));
    }

    double SSprite::IAccessDestinationWidthRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleHorizontal(FDestination.w));
    }

    double SSprite::IAccessDestinationHeightRectangle()
    {
        return(GVideo.IConvertFromPixelToRectangleVertical(FDestination.h));
    }

    void SSprite::IAccessDestinationXRectangleAbsolute(double AX)
    {
        FDestination.x = GVideo.IConvertFromRectangleToPixelHorizontal(AX);
    }

    void SSprite::IAccessDestinationYRectangleAbsolute(double AY)
    {
        FDestination.y = GVideo.IConvertFromRectangleToPixelVertical(AY);
    }

    void SSprite::IAccessDestinationWidthRectangleAbsolute(double AWidth)
    {
        FDestination.w = GVideo.IConvertFromRectangleToPixelHorizontal(AWidth);
    }

    void SSprite::IAccessDestinationHeightRectangleAbsolute(double AHeight)
    {
        FDestination.h = GVideo.IConvertFromRectangleToPixelVertical(AHeight);
    }

    void SSprite::IAccessDestinationXRectangleRelative(double AX)
    {
        FDestination.x += GVideo.IConvertFromRectangleToPixelHorizontal(AX);
    }

    void SSprite::IAccessDestinationYRectangleRelative(double AY)
    {
        FDestination.y += GVideo.IConvertFromRectangleToPixelVertical(AY);
    }

    void SSprite::IAccessDestinationWidthRectangleRelative(double AWidth)
    {
        FDestination.w += GVideo.IConvertFromRectangleToPixelHorizontal(AWidth);
    }

    void SSprite::IAccessDestinationHeightRectangleRelative(double AHeight)
    {
        FDestination.h += GVideo.IConvertFromRectangleToPixelVertical(AHeight);
    }

    double SSprite::IAccessDestinationXSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.x));
    }

    double SSprite::IAccessDestinationYSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.y));
    }

    double SSprite::IAccessDestinationWidthSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.w));
    }

    double SSprite::IAccessDestinationHeightSquare()
    {
        return(GVideo.IConvertFromPixelToSquare(FDestination.h));
    }

    void SSprite::IAccessDestinationXSquareAbsolute(double AX)
    {
        FDestination.x = GVideo.IConvertFromSquareToPixel(AX);
    }

    void SSprite::IAccessDestinationYSquareAbsolute(double AY)
    {
        FDestination.y = GVideo.IConvertFromSquareToPixel(AY);
    }

    void SSprite::IAccessDestinationWidthSquareAbsolute(double AWidth)
    {
        FDestination.w = GVideo.IConvertFromSquareToPixel(AWidth);
    }

    void SSprite::IAccessDestinationHeightSquareAbsolute(double AHeight)
    {
        FDestination.h = GVideo.IConvertFromSquareToPixel(AHeight);
    }

    void SSprite::IAccessDestinationXSquareRelative(double AX)
    {
        FDestination.x += GVideo.IConvertFromSquareToPixel(AX);
    }

    void SSprite::IAccessDestinationYSquareRelative(double AY)
    {
        FDestination.y += GVideo.IConvertFromSquareToPixel(AY);
    }

    void SSprite::IAccessDestinationWidthSquareRelative(double AWidth)
    {
        FDestination.w += GVideo.IConvertFromSquareToPixel(AWidth);
    }

    void SSprite::IAccessDestinationHeightSquareRelative(double AHeight)
    {
        FDestination.h += GVideo.IConvertFromSquareToPixel(AHeight);
    }

    void SSprite::IDraw()
    {
        FImage->IDraw(FSource , FDestination);
    }
}