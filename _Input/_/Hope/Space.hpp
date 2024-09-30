#pragma once

namespace NHope::NSpace
{
    namespace NEntity
    {
        struct SEntity;
    }
    
    struct SPartition
    {
        std::shared_ptr<NVideo::NSprite::SSprite> FGround;
        std::shared_ptr<NEntity::SEntity> FEntity;
    };
    
    inline struct SSpace
    {
        double FX;
        double FY;
        double FSpeedX;
        double FSpeedY;
        std::int64_t FIterationX;
        std::int64_t FIterationY;
        std::int64_t FWidth;
        std::int64_t FHeight;
        double FScaleX;
        double FScaleY;
        double FScaleLastX;
        double FScaleLastY;
        double FScaleXMinimum;
        double FScaleXMaximum;
        double FScaleYMinimum;
        double FScaleYMaximum;
        double FScalingX;
        double FScalingY;
        std::vector<std::vector<SPartition>> FMatrix;

        SSpace();
        void IPreupdate();
        double const& IX();
        double const& IY();
        double const& ISpeedX();
        double const& ISpeedY();
        std::int64_t const& IIterationX();
        std::int64_t const& IIterationY();
        std::int64_t const& IWidth();
        std::int64_t const& IHeight();
        double const& IScaleX();
        double const& IScaleY();
        double const& IScaleLastX();
        double const& IScaleLastY();
        double const& IScaleXMinimum();
        double const& IScaleXMaximum();
        double const& IScaleYMinimum();
        double const& IScaleYMaximum();
        double const& IScalingX();
        double const& IScalingY();
        std::vector<std::vector<SPartition>> const& IMatrix();
        void IX(double const& AValue);
        void IY(double const& AValue);
        void ISpeedX(double const& AValue);
        void ISpeedY(double const& AValue);
        void IIterationX(std::int64_t const& AValue);
        void IIterationY(std::int64_t const& AValue);
        void IWidth(std::int64_t const& AValue);
        void IHeight(std::int64_t const& AValue);
        void IScaleX(double const& AValue);
        void IScaleY(double const& AValue);
        void IScaleLastX(double const& AValue);
        void IScaleLastY(double const& AValue);
        void IScaleXMinimum(double const& AValue);
        void IScaleXMaximum(double const& AValue);
        void IScaleYMinimum(double const& AValue);
        void IScaleYMaximum(double const& AValue);
        void IScalingX(double const& AValue);
        void IScalingY(double const& AValue);
        void IMatrix(std::vector<std::vector<SPartition>> const& AValue);
        void IConstruct();
        void IDeconstruct();
        bool IMove(const std::string& AGround);
        void IPostupdate();
        ~SSpace();
    }
    GSpace;
}