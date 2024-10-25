#pragma once

namespace NHope::NVideo
{
    struct SFont
    {       
        std::string FPath;
        std::vector<std::shared_ptr<SImage>> FDigits;
        std::vector<std::shared_ptr<SImage>> FUppercases;
        std::vector<std::shared_ptr<SImage>> FLowercases;
        std::vector<std::shared_ptr<SImage>> FStrings;

        SFont(std::string const& APath);
        SImage* IDigit(char const& ACode);
        SImage* IUppercase(char const& ACode);
        SImage* ILowercase(char const& ACode);
        SImage* IString(std::string const& AString);
        ~SFont();
    };
}