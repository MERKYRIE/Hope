#pragma once

namespace NHope
{
    namespace NAudio
    {
        struct STrack;
        struct SSound;
    }

    inline struct SAudio
    {
        std::vector<std::shared_ptr<NAudio::STrack>> FTracks;
        std::vector<std::shared_ptr<NAudio::SSound>> FSounds;

        SAudio();
        void IPreupdate();
        std::vector<std::shared_ptr<NAudio::STrack>> const& ITracks();
        std::vector<std::shared_ptr<NAudio::SSound>> const& ISounds();
        void ITracks(std::vector<std::shared_ptr<NAudio::STrack>> const& AValue);
        void ISounds(std::vector<std::shared_ptr<NAudio::SSound>> const& AValue);
        NAudio::STrack* IAccessTrack(const std::string& APath);
        NAudio::SSound* IAccessSound(const std::string& APath);
        void IPostupdate();
        ~SAudio();
    }
    GAudio;
}