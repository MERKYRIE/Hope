#pragma once

namespace NHope
{
    namespace NKeyboard
    {
        struct SKey;
    }
    
    inline struct SKeyboard
    {
        std::unordered_map<std::string , std::shared_ptr<NKeyboard::SKey>> FKeys;
        std::unordered_map<std::int64_t , std::string> FKeysAdaptors;

        SKeyboard();
        void IPreupdate();
        void IPostupdate(SDL_Event const& AEvent);
        ~SKeyboard();
    }
    GKeyboard;
}