#include"Hope.hpp"

#include"Video/Font.hpp"
#include"Video/Image.hpp"
#include"Video/Sprite.hpp"

#include"Space/Entity.hpp"

namespace NHope::NSpace
{
    SSpace::SSpace()
    {
        FX = 0.0;
        FY = 0.0;
        FSpeedX = 0.0025;
        FSpeedY = 0.0025;
        FIterationX = 0;
        FIterationY = 0;
        FWidth = 10;
        FHeight = 10;
        FScaleX = 0.05;
        FScaleY = 0.05;
        FScaleLastX = FScaleX;
        FScaleLastY = FScaleY;
        FScaleXMinimum = 0.05;
        FScaleXMaximum = 0.2;
        FScaleYMinimum = 0.05;
        FScaleYMaximum = 0.2;
        FScalingX = 2.0;
        FScalingY = 2.0;
        FMatrix.resize(FWidth);
        for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
        {
            FMatrix[FIterationX].resize(FHeight);
            for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)
            {
                FMatrix[FIterationX][FIterationY].FGround = std::make_shared<NVideo::NSprite::SSprite>();
                FMatrix[FIterationX][FIterationY].FGround->ILoad(NVideo::GVideo.IAccessFont("/Consolas.ttf")->IAccessString("Dirt"));
            }
            FMatrix[FIterationX].shrink_to_fit();
        }
        FMatrix.shrink_to_fit();
        FMatrix[0][0].FEntity = std::make_shared<NEntity::SEntity>();
        FMatrix[9][0].FGround->ILoad(NVideo::GVideo.IAccessFont("/Consolas.ttf")->IAccessString("Food"));
        FMatrix[0][9].FGround->ILoad(NVideo::GVideo.IAccessFont("/Consolas.ttf")->IAccessString("Water"));
    }

    void SSpace::IPreupdate()
    {
        FScaleLastX = FScaleX;
        FScaleLastY = FScaleY;
        FScaleX = std::clamp(FScaleX * std::pow(FScalingX , NMouse::GMouse.IWheelState()) , FScaleXMinimum , FScaleXMaximum);
        FScaleY = std::clamp(FScaleY * std::pow(FScalingY , NMouse::GMouse.IWheelState()) , FScaleYMinimum , FScaleYMaximum);
        FX -= FSpeedX * NMouse::GMouse.IXsHeldRelative()[SDL_BUTTON_MIDDLE] / FScaleLastX - (FScaleLastX != FScaleX) * NMouse::GMouse.IWheelState() * NMouse::GMouse.IAbsoluteXSquare() / std::max(FScaleLastX , FScaleX);
        FY -= FSpeedY * NMouse::GMouse.IYsHeldRelative()[SDL_BUTTON_MIDDLE] / FScaleLastY - (FScaleLastY != FScaleY) * NMouse::GMouse.IWheelState() * NMouse::GMouse.IAbsoluteYSquare() / std::max(FScaleLastY , FScaleY);
        for(FIterationX = 0 ; FIterationX < FWidth ; FIterationX++)
        {
            for(FIterationY = 0 ; FIterationY < FHeight ; FIterationY++)
            {
                FMatrix[FIterationX][FIterationY].FGround
                ->IAccessDestinationXSquareAbsolute(FScaleX * (-FX + FIterationX))->IAccessDestinationYSquareAbsolute(FScaleY * (-FY + FIterationY))
                ->IAccessDestinationWidthSquareAbsolute(FScaleX)->IAccessDestinationHeightSquareAbsolute(FScaleY)
                ->IDraw();
                if(FMatrix[FIterationX][FIterationY].FEntity)
                {
                    FMatrix[FIterationX][FIterationY].FEntity->IUpdate();
                    FMatrix[FIterationX][FIterationY].FEntity->ISprite()
                    ->IAccessDestinationXSquareAbsolute(FScaleX * (-FX + FIterationX))->IAccessDestinationYSquareAbsolute(FScaleY * (-FY + FIterationY))
                    ->IAccessDestinationWidthSquareAbsolute(FScaleX)->IAccessDestinationHeightSquareAbsolute(FScaleY)
                    ->IDraw();
                }
            }
        }
    }

    double const& SSpace::IX()
    {
        return(FX);
    }

    double const& SSpace::IY()
    {
        return(FY);
    }

    double const& SSpace::ISpeedX()
    {
        return(FSpeedX);
    }

    double const& SSpace::ISpeedY()
    {
        return(FSpeedY);
    }

    const std::int64_t& SSpace::IIterationX()
    {
        return(FIterationX);
    }

    const std::int64_t& SSpace::IIterationY()
    {
        return(FIterationY);
    }

    const std::int64_t& SSpace::IWidth()
    {
        return(FWidth);
    }

    const std::int64_t& SSpace::IHeight()
    {
        return(FHeight);
    }

    double const& SSpace::IScaleX()
    {
        return(FScaleX);
    }

    double const& SSpace::IScaleY()
    {
        return(FScaleY);
    }

    double const& SSpace::IScaleLastX()
    {
        return(FScaleLastX);
    }

    double const& SSpace::IScaleLastY()
    {
        return(FScaleLastY);
    }

    double const& SSpace::IScaleXMinimum()
    {
        return(FScaleXMinimum);
    }

    double const& SSpace::IScaleXMaximum()
    {
        return(FScaleXMaximum);
    }

    double const& SSpace::IScaleYMinimum()
    {
        return(FScaleYMinimum);
    }

    double const& SSpace::IScaleYMaximum()
    {
        return(FScaleYMaximum);
    }

    double const& SSpace::IScalingX()
    {
        return(FScalingX);
    }

    double const& SSpace::IScalingY()
    {
        return(FScalingY);
    }

    std::vector<std::vector<SPartition>> const& SSpace::IMatrix()
    {
        return(FMatrix);
    }

    void SSpace::IX(double const& AValue)
    {
        FX = AValue;
    }

    void SSpace::IY(double const& AValue)
    {
        FY = AValue;
    }

    void SSpace::ISpeedX(double const& AValue)
    {
        FSpeedX = AValue;
    }

    void SSpace::ISpeedY(double const& AValue)
    {
        FSpeedY = AValue;
    }

    void SSpace::IIterationX(const std::int64_t& AValue)
    {
        FIterationX = AValue;
    }

    void SSpace::IIterationY(const std::int64_t& AValue)
    {
        FIterationY = AValue;
    }

    void SSpace::IWidth(const std::int64_t& AValue)
    {
        FWidth = AValue;
    }

    void SSpace::IHeight(const std::int64_t& AValue)
    {
        FHeight = AValue;
    }

    void SSpace::IScaleX(double const& AValue)
    {
        FScaleX = AValue;
    }

    void SSpace::IScaleY(double const& AValue)
    {
        FScaleY = AValue;
    }

    void SSpace::IScaleLastX(double const& AValue)
    {
        FScaleLastX = AValue;
    }

    void SSpace::IScaleLastY(double const& AValue)
    {
        FScaleLastY = AValue;
    }

    void SSpace::IScaleXMinimum(double const& AValue)
    {
        FScaleXMinimum = AValue;
    }

    void SSpace::IScaleXMaximum(double const& AValue)
    {
        FScaleXMaximum = AValue;
    }

    void SSpace::IScaleYMinimum(double const& AValue)
    {
        FScaleYMinimum = AValue;
    }

    void SSpace::IScaleYMaximum(double const& AValue)
    {
        FScaleYMaximum = AValue;
    }

    void SSpace::IScalingX(double const& AValue)
    {
        FScalingX = AValue;
    }

    void SSpace::IScalingY(double const& AValue)
    {
        FScalingY = AValue;
    }

    void SSpace::IMatrix(std::vector<std::vector<SPartition>> const& AValue)
    {
        FMatrix = AValue;
    }

    void SSpace::IConstruct()
    {
    
    }

    bool SSpace::IMove(const std::string& AGround)
    {
        for(std::int64_t LX{0} ; LX < FWidth ; LX++)
        {
            for(std::int64_t LY{0} ; LY < FHeight ; LY++)
            {
                if(FMatrix[LX][LY].FGround->IImage()->IIs(AGround))
                {
                    if(std::abs(LX - FIterationX) <= 1 && std::abs(LY - FIterationY) <= 1)
                    {
                        return(true);
                    }
                    if(!FMatrix[FIterationX + std::clamp<std::int64_t>(LX - FIterationX , -1 , +1)][FIterationY + std::clamp<std::int64_t>(LY - FIterationY , -1 , +1)].FEntity)
                    {
                        FMatrix[FIterationX + std::clamp<std::int64_t>(LX - FIterationX , -1 , +1)][FIterationY + std::clamp<std::int64_t>(LY - FIterationY , -1 , +1)].FEntity
                        =
                        FMatrix[FIterationX][FIterationY].FEntity;
                        FMatrix[FIterationX][FIterationY].FEntity.reset();
                    }
                }
            }
        }
        return(false);
    }

    void SSpace::IPostupdate()
    {
    
    }

    SSpace::~SSpace()
    {
    
    }
}