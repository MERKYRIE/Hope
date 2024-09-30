#pragma once

namespace NHope::NSpace::NEntity
{
    struct SEntity
    {
        std::shared_ptr<NVideo::NSprite::SSprite> FSprite;
        double FTimer;
        double FTime;
        double FHunger;
        double FThirst;

        SEntity();
        NVideo::NSprite::SSprite* ISprite();
        SEntity* ISprite(NVideo::NSprite::SSprite* ASprite);
        SEntity* IUpdate();
    };
}