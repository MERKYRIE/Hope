#include"Hope.hpp"

#include"Image.hpp"

namespace NHope::NVideo
{
    SImage::SImage(std::string const& APath)
    {
        FPath = APath.substr(APath.find('/'));
        FHandle = IMG_LoadTexture(GVideo.IRenderer() , APath.c_str());
        GDebug.ISimpleDirectMediaLayerHandleError(FHandle);
    }

    SImage::SImage(TTF_Font* const& AFont , std::string const& AString)
    {
        FPath = AString;
        SDL_Surface* LSurface
        {
            TTF_RenderUTF8_LCD_Wrapped
            (
                AFont
                ,
                (std::string{} + "\n" + " " + AString + " " + "\n").c_str()
                ,
                SDL_Color{.r{100} , .g{100} , .b{100} , .a{SDL_ALPHA_OPAQUE}}
                ,
                SDL_Color{.r{0} , .g{0} , .b{0} , .a{SDL_ALPHA_OPAQUE}}
                ,
                0
            )
        };
        GDebug.ISimpleDirectMediaLayerHandleError(LSurface);
        FHandle = SDL_CreateTextureFromSurface(GVideo.IRenderer() , LSurface);
        GDebug.ISimpleDirectMediaLayerHandleError(FHandle);
        SDL_FreeSurface(LSurface);
    }

    std::int32_t SImage::IWidth()
    {
        std::int32_t LWidth;
        SDL_QueryTexture(FHandle , nullptr , nullptr , &LWidth , nullptr);
        return LWidth;
    }

    std::int32_t SImage::IHeight()
    {
        std::int32_t LHeight;
        SDL_QueryTexture(FHandle , nullptr , nullptr , nullptr , &LHeight);
        return LHeight;
    }

    std::int32_t SImage::IMinimum()
    {
        std::int32_t LWidth;
        std::int32_t LHeight;
        SDL_QueryTexture(FHandle , nullptr , nullptr , &LWidth , &LHeight);
        return(std::min(LWidth , LHeight));
    }

    std::int32_t SImage::IMaximum()
    {
        std::int32_t LWidth;
        std::int32_t LHeight;
        SDL_QueryTexture(FHandle , nullptr , nullptr , &LWidth , &LHeight);
        return(std::max(LWidth , LHeight));
    }

    void SImage::IDraw(SDL_Rect const& ASource , SDL_Rect const& ADestination)
    {
        SDL_RenderCopy(GVideo.IRenderer() , FHandle , &ASource , &ADestination);
    }

    SImage::~SImage()
    {
        SDL_DestroyTexture(FHandle);
    }
}