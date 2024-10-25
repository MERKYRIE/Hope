#pragma once

namespace NHope::NVideo
{
    struct SSprite
    {
        SImage* FImage;
        SDL_Rect FSource;
        SDL_Rect FDestination;

        SSprite();
        void ILoad(SImage* AImage);
        void IUnload();
        std::int32_t IAccessSourceX();
        std::int32_t IAccessSourceY();
        std::int32_t IAccessSourceWidth();
        std::int32_t IAccessSourceHeight();
        void IAccessSourceXAbsolute(std::int32_t AX);
        void IAccessSourceYAbsolute(std::int32_t AY);
        void IAccessSourceWidthAbsolute(std::int32_t AWidth);
        void IAccessSourceHeightAbsolute(std::int32_t AHeight);
        void IAccessSourceXRelative(std::int32_t AX);
        void IAccessSourceYRelative(std::int32_t AY);
        void IAccessSourceWidthRelative(std::int32_t AWidth);
        void IAccessSourceHeightRelative(std::int32_t AHeight);
        double IAccessSourceXRectangle();
        double IAccessSourceYRectangle();
        double IAccessSourceWidthRectangle();
        double IAccessSourceHeightRectangle();
        void IAccessSourceXRectangleAbsolute(double AX);
        void IAccessSourceYRectangleAbsolute(double AY);
        void IAccessSourceWidthRectangleAbsolute(double AWidth);
        void IAccessSourceHeightRectangleAbsolute(double AHeight);
        void IAccessSourceXRectangleRelative(double AX);
        void IAccessSourceYRectangleRelative(double AY);
        void IAccessSourceWidthRectangleRelative(double AWidth);
        void IAccessSourceHeightRectangleRelative(double AHeight);
        double IAccessSourceXSquare();
        double IAccessSourceYSquare();
        double IAccessSourceWidthSquare();
        double IAccessSourceHeightSquare();
        void IAccessSourceXSquareAbsolute(double AX);
        void IAccessSourceYSquareAbsolute(double AY);
        void IAccessSourceWidthSquareAbsolute(double AWidth);
        void IAccessSourceHeightSquareAbsolute(double AHeight);
        void IAccessSourceXSquareRelative(double AX);
        void IAccessSourceYSquareRelative(double AY);
        void IAccessSourceWidthSquareRelative(double AWidth);
        void IAccessSourceHeightSquareRelative(double AHeight);
        std::int32_t IAccessDestinationX();
        std::int32_t IAccessDestinationY();
        std::int32_t IAccessDestinationWidth();
        std::int32_t IAccessDestinationHeight();
        void IAccessDestinationXAbsolute(std::int32_t AX);
        void IAccessDestinationYAbsolute(std::int32_t AY);
        void IAccessDestinationWidthAbsolute(std::int32_t AWidth);
        void IAccessDestinationHeightAbsolute(std::int32_t AHeight);
        void IAccessDestinationXRelative(std::int32_t AX);
        void IAccessDestinationYRelative(std::int32_t AY);
        void IAccessDestinationWidthRelative(std::int32_t AWidth);
        void IAccessDestinationHeightRelative(std::int32_t AHeight);
        double IAccessDestinationXRectangle();
        double IAccessDestinationYRectangle();
        double IAccessDestinationWidthRectangle();
        double IAccessDestinationHeightRectangle();
        void IAccessDestinationXRectangleAbsolute(double AX);
        void IAccessDestinationYRectangleAbsolute(double AY);
        void IAccessDestinationWidthRectangleAbsolute(double AWidth);
        void IAccessDestinationHeightRectangleAbsolute(double AHeight);
        void IAccessDestinationXRectangleRelative(double AX);
        void IAccessDestinationYRectangleRelative(double AY);
        void IAccessDestinationWidthRectangleRelative(double AWidth);
        void IAccessDestinationHeightRectangleRelative(double AHeight);
        double IAccessDestinationXSquare();
        double IAccessDestinationYSquare();
        double IAccessDestinationWidthSquare();
        double IAccessDestinationHeightSquare();
        void IAccessDestinationXSquareAbsolute(double AX);
        void IAccessDestinationYSquareAbsolute(double AY);
        void IAccessDestinationWidthSquareAbsolute(double AWidth);
        void IAccessDestinationHeightSquareAbsolute(double AHeight);
        void IAccessDestinationXSquareRelative(double AX);
        void IAccessDestinationYSquareRelative(double AY);
        void IAccessDestinationWidthSquareRelative(double AWidth);
        void IAccessDestinationHeightSquareRelative(double AHeight);
        void IDraw();
    };
}