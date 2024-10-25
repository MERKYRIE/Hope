#include"Hope.hpp"

#include"Sound.hpp"

namespace NHope::NAudio
{
    SSound::SSound(std::string const& APath)
    {
        FPath = APath.substr(APath.find('/'));
        GDebug.ISimpleDirectMediaLayerHandleError(FHandle = Mix_LoadWAV(APath.c_str()));
        FChannel = Mix_AllocateChannels(SDL_QUERY);
        GDebug.IError(Mix_AllocateChannels(Mix_AllocateChannels(SDL_QUERY) + 1) != FChannel + 1);
    }

    void SSound::IPlay()
    {
        GDebug.ISimpleDirectMediaLayerCodeError(Mix_PlayChannel(FChannel , FHandle , 0) != FChannel);
    }

    bool SSound::IState()
    {
        return(Mix_Playing(FChannel));
    }

    SSound::~SSound()
    {
        Mix_FreeChunk(FHandle);
    }
}