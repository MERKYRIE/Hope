#pragma once

namespace NHope::NAudio
{
    struct STrack
    {
        std::string FPath;
        Mix_Music* FHandle;

        STrack(std::string const& APath);
        void IPlay();
        void IPause();
        void IResume();
        void IStop();
        void IVolume(std::uint8_t const& ALevel);
        ~STrack();
    };
}