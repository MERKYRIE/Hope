#include"Hope.hpp"

#include"Track.hpp"

namespace NHope::NAudio
{
    STrack::STrack(std::string const& APath)
    {
        FPath = APath.substr(APath.find('/'));
        GDebug.ISimpleDirectMediaLayerHandleError(FHandle = Mix_LoadMUS(APath.c_str()));
    }

    void STrack::IPlay()
    {
        GDebug.ISimpleDirectMediaLayerCodeError(Mix_PlayMusic(FHandle , 0));
    }

    void STrack::IPause()
    {
        Mix_PauseMusic();
    }

    void STrack::IResume()
    {
        Mix_ResumeMusic();
    }

    void STrack::IStop()
    {
        Mix_HaltMusic();
    }

    void STrack::IVolume(std::uint8_t const& ALevel)
    {
        Mix_VolumeMusic(ALevel);
        GDebug.IError(Mix_VolumeMusic(SDL_QUERY) != ALevel);
    }

    STrack::~STrack()
    {
        Mix_FreeMusic(FHandle);
    }
}