#pragma once

#include<array>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<numbers>
#include<random>
#include<source_location>
#include<string>
#include<unordered_map>
#include<variant>
#include<vector>

#pragma warning(push)
    #pragma warning(disable : 26819)

    #include"../SimpleDirectMediaLayer/SDL.h"
    #include"../SimpleDirectMediaLayer/Image/SDL_image.h"
    #include"../SimpleDirectMediaLayer/Mixer/SDL_mixer.h"
    #include"../SimpleDirectMediaLayer/TrueTypeFont/SDL_ttf.h"
#pragma warning(pop)

#pragma warning(disable : 26495)

namespace NHope
{
    inline struct SHope
    {
        SHope();
        void IUpdate();
        ~SHope();
    }
    GHope;
}

#include"Hope/Audio.hpp"
#include"Hope/Debug.hpp"
#include"Hope/Keyboard.hpp"
#include"Hope/Mouse.hpp"
#include"Hope/Time.hpp"
#include"Hope/Video.hpp"
#include"Hope/Space.hpp"
#include"Hope/Interface.hpp"