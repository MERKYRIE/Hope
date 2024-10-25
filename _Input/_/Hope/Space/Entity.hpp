#pragma once

namespace NHope::NSpace
{
    struct SEntity
    {
        std::shared_ptr<NVideo::SSprite> FSprite;
        double FTimer;
        double FTime;
        double FHunger;
        double FThirst;

        SEntity();
        void IUpdate();
        ~SEntity();
    };
}