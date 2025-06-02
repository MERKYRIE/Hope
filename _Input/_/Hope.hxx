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
        void IInitiate();
        ~SHope();
    }
    GHope;

    namespace NHope
    {
        namespace NAudio
        {
            struct SSound;
            struct STrack;
        }
        
        namespace NKeyboard
        {
            struct SKey;
        }
            
        namespace NMouse
        {
            struct SAbsolute;
            struct SButton;
            struct SCursor;
            struct SPixel;
            struct SRectangle;
            struct SRelative;
            struct SSquare;
            struct SWheel;
        }

        namespace NSpace
        {
            struct SEntity;
            struct SImage;
            struct SPartition;
            struct STerrain;
        }

        namespace NVideo
        {
            struct SFont;
            struct SImage;
        }
    }
}

#include"Hope/Audio/Sound.hxx"
#include"Hope/Audio/Track.hxx"
#include"Hope/Keyboard/Key.hxx"
#include"Hope/Mouse/Absolute.hxx"
#include"Hope/Mouse/Button.hxx"
#include"Hope/Mouse/Cursor.hxx"
#include"Hope/Mouse/Pixel.hxx"
#include"Hope/Mouse/Rectangle.hxx"
#include"Hope/Mouse/Relative.hxx"
#include"Hope/Mouse/Square.hxx"
#include"Hope/Mouse/Wheel.hxx"
#include"Hope/Space/Entity.hxx"
#include"Hope/Space/Image.hxx"
#include"Hope/Space/Partition.hxx"
#include"Hope/Space/Terrain.hxx"
#include"Hope/Video/Font.hxx"
#include"Hope/Video/Image.hxx"

#include"Hope/Debug.hxx"
#include"Hope/Audio.hxx"
#include"Hope/Keyboard.hxx"
#include"Hope/Mouse.hxx"
#include"Hope/Time.hxx"
#include"Hope/Video.hxx"
#include"Hope/Space.hxx"
#include"Hope/Interface.hxx"