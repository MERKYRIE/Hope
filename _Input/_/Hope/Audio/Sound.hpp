#pragma once

namespace NHope::NAudio
{
    struct SSound
    {
        std::string FPath;
        Mix_Chunk* FHandle;
        std::int32_t FChannel;

        SSound(std::string const& APath);
        void IPlay();
        bool IState();
        ~SSound();
    };
}