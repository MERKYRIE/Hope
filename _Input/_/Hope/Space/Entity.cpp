#include"Hope.hpp"

#include"Hope/Video/Font.hpp"
#include"Hope/Video/Sprite.hpp"

#include"Entity.hpp"

namespace NHope::NSpace::NEntity
{
    SEntity::SEntity()
    {
        FSprite = std::make_shared<NVideo::NSprite::SSprite>();
        FSprite->ILoad(NVideo::GVideo.IAccessFont("/Consolas.ttf")->IAccessString("Dwarf"));
        FTimer = 0.0;
        FTime = 0.5;
        FHunger = 0.0;
        FThirst = 0.0;
    }
    
    NVideo::NSprite::SSprite* SEntity::ISprite()
    {
        return(FSprite.get());
    }

    SEntity* SEntity::ISprite(NVideo::NSprite::SSprite* ASprite)
    {
        FSprite.reset(ASprite);
        return(this);
    }

    SEntity* SEntity::IUpdate()
    {
        FHunger += NTime::GTime.ITimepointRelative() / 240'000.0;
        if(FHunger >= 1.0)
        {
            return(this);
        }
        FThirst += NTime::GTime.ITimepointRelative() / 60'000.0;
        if(FThirst >= 1.0)
        {
            return(this);
        }
        FTimer += NTime::GTime.ITimepointRelative() / 1000.0;
        if(FHunger >= 0.05 && FTimer >= FTime)
        {
            //if(GSpace->AMove("Food"))
            {
                FHunger = 0.0;
            }
        }
        if(FThirst >= 0.05 && FTimer >= FTime)
        {
            //if(GSpace->AMove("Water"))
            {
                FThirst = 0.0;
            }
        }
        if(FTimer >= FTime)
        {
            FTimer = 0.0;
        }
        return(this);
    }
}