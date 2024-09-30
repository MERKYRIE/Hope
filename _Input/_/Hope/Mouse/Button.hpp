#pragma once

namespace NHope::NMouse::NButton
{
    struct SButton
    {
        std::unordered_map<std::string , bool> FStates;

        SButton();

        std::unordered_map<std::string , bool> const& IStates();

        SButton* IStates(std::unordered_map<std::string , bool> const& AValue);

        SButton* IUpdate(SDL_Event const& AEvent);

        ~SButton();
    };
}