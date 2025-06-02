#pragma once

namespace NHope::NHope
{
    inline struct SKeyboard
    {
        std::unordered_map<std::string , std::shared_ptr<NKeyboard::SKey>> FKeys;
        std::unordered_map<std::int64_t , std::string> FKeysAdaptors;

        SKeyboard();
        void IUpdate();
    }
    GKeyboard;
}