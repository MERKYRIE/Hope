#pragma once

namespace NHope::NVideo
{
    struct SImage
    {
        std::string FPath;
        SDL_Texture* FHandle;

        SImage(std::string const& APath);
        SImage(TTF_Font* const& AFont , std::string const& AString);
        std::int32_t IWidth();
        std::int32_t IHeight();
        std::int32_t IMinimum();
        std::int32_t IMaximum();
        void IDraw(SDL_Rect const& ASource , SDL_Rect const& ADestination);
        ~SImage();
    };
}