#include"Hope.hpp"

#include"Button.hpp"

namespace NHope::NMouse::NButton
{
    SButton::SButton()
    {
        FStates["Pressed"] = false;
        FStates["Held"] = false;
        FStates["Released"] = false;
    }

    std::unordered_map<std::string , bool> const& SButton::IStates()
    {
        return(FStates);
    }

    SButton* SButton::IStates(std::unordered_map<std::string , bool> const& AValue)
    {
        FStates = AValue;
        return(this);
    }

    SButton* SButton::IUpdate(SDL_Event const& AEvent)
    {
        switch(AEvent.type)
        {
            case(SDL_MOUSEBUTTONDOWN):
                FStates["Pressed"] = true;
                FStates["Held"] = true;
                FStates["Released"] = false;
            break;
            case(SDL_MOUSEBUTTONUP):
                FStates["Pressed"] = false;
                FStates["Held"] = false;
                FStates["Released"] = true;
            break;
        }
        return(this);
    }

    SButton::~SButton()
    {
    
    }
}