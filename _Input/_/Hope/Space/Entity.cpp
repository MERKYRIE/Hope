#include"Hope.hpp"

#include"Hope/Video/Font.hpp"
#include"Hope/Video/Sprite.hpp"

#include"Entity.hpp"

namespace NHope::NSpace
{
    SEntity::SEntity()
    {
        FSprite = std::make_shared<NVideo::SSprite>();
        FSprite->ILoad(GVideo.IAccessFont("/Consolas.ttf")->IString("Dwarf"));
        FTimer = 0.0;
        FTime = 0.5;
        FHunger = 0.0;
        FThirst = 0.0;
    }

    void SEntity::IUpdate()
    {
        FHunger += GTime.ITimepointRelative() / 240'000.0;
        if(FHunger >= 1.0)
        {
            return;
        }
        FThirst += GTime.ITimepointRelative() / 60'000.0;
        if(FThirst >= 1.0)
        {
            return;
        }
        FTimer += GTime.ITimepointRelative() / 1000.0;
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
    }

    SEntity::~SEntity()
    {
    
    }
}