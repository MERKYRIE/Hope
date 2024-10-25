#include"Hope.hpp"

#include"Audio/Track.hpp"
#include"Audio/Sound.hpp"

namespace NHope
{
    SAudio::SAudio()
    {
        GDebug.ISimpleDirectMediaLayerMaskError(Mix_Init(MIX_INIT_MP3));
        GDebug.ISimpleDirectMediaLayerCodeError(Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY , MIX_DEFAULT_FORMAT , MIX_DEFAULT_CHANNELS , 2048 , nullptr , 0));
        std::int32_t LFrequency;
        std::uint16_t LFormat;
        std::int32_t LChannels;
        GDebug.IError(!Mix_QuerySpec(&LFrequency , &LFormat , &LChannels));
        GDebug.IError(LFrequency != MIX_DEFAULT_FREQUENCY || LFormat != MIX_DEFAULT_FORMAT || LChannels != MIX_DEFAULT_CHANNELS);
        GDebug.IError(Mix_AllocateChannels(0));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Sounds"})
        {
            if(LEntry.path().extension() == ".wav")
            {
                FSounds.emplace_back(std::make_shared<NAudio::SSound>(LEntry.path().generic_string()));
            }
        }
        FSounds.shrink_to_fit();
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Tracks"})
        {
            if(LEntry.path().extension() == ".mp3")
            {
                FTracks.emplace_back(std::make_shared<NAudio::STrack>(LEntry.path().generic_string()));
            }
        }
        FTracks.shrink_to_fit();
    }

    void SAudio::IPreupdate()
    {
    
    }

    std::vector<std::shared_ptr<NAudio::STrack>> const& SAudio::ITracks()
    {
        return(FTracks);
    }

    std::vector<std::shared_ptr<NAudio::SSound>> const& SAudio::ISounds()
    {
        return(FSounds);
    }

    void SAudio::ITracks(std::vector<std::shared_ptr<NAudio::STrack>> const& AValue)
    {
        FTracks = AValue;
    }

    void SAudio::ISounds(std::vector<std::shared_ptr<NAudio::SSound>> const& AValue)
    {
        FSounds = AValue;
    }

    NAudio::STrack* SAudio::IAccessTrack(const std::string& APath)
    {
        std::vector<std::shared_ptr<NAudio::STrack>>::iterator LIterator
        {
            std::find_if(FTracks.begin() , FTracks.end() , [&](std::shared_ptr<NAudio::STrack>& LTrack){return(LTrack->FPath == APath);})
        };
        return(LIterator->get());
    }

    NAudio::SSound* SAudio::IAccessSound(const std::string& APath)
    {
        std::vector<std::shared_ptr<NAudio::SSound>>::iterator LIterator
        {
            std::find_if(FSounds.begin() , FSounds.end() , [&](std::shared_ptr<NAudio::SSound>& LSound){return(LSound->FPath == APath);})
        };
        return(LIterator->get());
    }

    void SAudio::IPostupdate()
    {
    
    }

    SAudio::~SAudio()
    {
        FTracks.clear();
        FSounds.clear();
        Mix_CloseAudio();
        Mix_Quit();
    }
}