#include"Hope.hpp"

#include"Video/Font.hpp"
#include"Video/Image.hpp"

namespace NHope
{
    SVideo::SVideo()
    {
        GDebug.ISimpleDirectMediaLayerHandleError(FWindow = SDL_CreateWindow("Hope" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP));
        GDebug.ISimpleDirectMediaLayerHandleError(FRenderer = SDL_CreateRenderer(FWindow , -1 , SDL_RENDERER_ACCELERATED));
        SDL_DisplayMode LDisplayMode;
        GDebug.ISimpleDirectMediaLayerCodeError(SDL_GetWindowDisplayMode(FWindow , &LDisplayMode));
        FWidth = LDisplayMode.w;
        FHeight = LDisplayMode.h;
        FMinimum = std::min(FWidth , FHeight);
        FMaximum = std::max(FWidth , FHeight);
        FRatio = static_cast<double>(FWidth) / static_cast<double>(FHeight);
        FRatioInversed = static_cast<double>(FHeight) / static_cast<double>(FWidth);
        GDebug.ISimpleDirectMediaLayerCodeError(TTF_Init());
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Fonts"})
        {
            if(LEntry.path().extension() == ".ttf")
            {
                FFonts.emplace_back(std::make_shared<NVideo::SFont>(LEntry.path().generic_string()));
            }
        }
        FFonts.shrink_to_fit();
        GDebug.ISimpleDirectMediaLayerMaskError(IMG_Init(IMG_INIT_PNG));
        for(const std::filesystem::directory_entry& LEntry : std::filesystem::recursive_directory_iterator{"Images"})
        {
            if(LEntry.path().extension() == ".png")
            {
                FImages.emplace_back(std::make_shared<NVideo::SImage>(LEntry.path().generic_string()));
            }
        }
        FImages.shrink_to_fit();
    }

    void SVideo::IPreupdate()
    {
        SDL_RenderClear(FRenderer);
    }
    
    SDL_Window* const& SVideo::IWindow()
    {
        return(FWindow);
    }
    
    SDL_Renderer* const& SVideo::IRenderer()
    {
        return(FRenderer);
    }
    
    std::int32_t const& SVideo::IWidth()
    {
        return(FWidth);
    }

    std::int32_t const& SVideo::IHeight()
    {
        return(FHeight);
    }

    std::int32_t const& SVideo::IMinimum()
    {
        return(FMinimum);
    }

    std::int32_t const& SVideo::IMaximum()
    {
        return(FMaximum);
    }

    double const& SVideo::IRatio()
    {
        return(FRatio);
    }

    double const& SVideo::IRatioInversed()
    {
        return(FRatioInversed);
    }

    std::vector<std::shared_ptr<NVideo::SFont>> const& SVideo::IFonts()
    {
        return(FFonts);
    }

    std::vector<std::shared_ptr<NVideo::SImage>> const& SVideo::IImages()
    {
        return(FImages);
    }

    void SVideo::IWindow(SDL_Window* const& AValue)
    {
        FWindow = AValue;
    }

    void SVideo::IRenderer(SDL_Renderer* const& AValue)
    {
        FRenderer = AValue;
    }

    void SVideo::IWidth(std::int32_t const& AValue)
    {
        FWidth = AValue;
    }

    void SVideo::IHeight(std::int32_t const& AValue)
    {
        FHeight = AValue;
    }

    void SVideo::IMinimum(std::int32_t const& AValue)
    {
        FMinimum = AValue;
    }

    void SVideo::IMaximum(std::int32_t const& AValue)
    {
        FMaximum = AValue;
    }

    void SVideo::IRatio(double const& AValue)
    {
        FRatio = AValue;
    }

    void SVideo::IRatioInversed(double const& AValue)
    {
        FRatioInversed = AValue;
    }

    void SVideo::IFonts(std::vector<std::shared_ptr<NVideo::SFont>> const& AValue)
    {
        FFonts = AValue;
    }

    void SVideo::IImages(std::vector<std::shared_ptr<NVideo::SImage>> const& AValue)
    {
        FImages = AValue;
    }

    NVideo::SFont* SVideo::IAccessFont(const std::string& APath)
    {
        std::vector<std::shared_ptr<NVideo::SFont>>::iterator LIterator
        {
            std::find_if(FFonts.begin() , FFonts.end() , [&](std::shared_ptr<NVideo::SFont>& LFont){return(LFont->FPath == APath);})
        };
        return(LIterator->get());
    }

    NVideo::SImage* SVideo::IAccessImageSpecific(const std::string& APath)
    {
        std::vector<std::shared_ptr<NVideo::SImage>>::iterator LIterator
        {
            std::find_if(FImages.begin() , FImages.end() , [&](std::shared_ptr<NVideo::SImage>& LImage){return(LImage->FPath == APath);})
        };
        return(LIterator->get());
    }

    NVideo::SImage* SVideo::IAccessImageRandom()
    {
        std::random_device LGenerator;
        std::uniform_int_distribution<std::uintmax_t> LDistributor{0 , FImages.size() - 1};
        return(FImages[LDistributor(LGenerator)].get());
    }

    double SVideo::IConvertFromPixelToRectangleHorizontal(std::int32_t APixel)
    {
        return(static_cast<double>(APixel) / static_cast<double>(FWidth));
    }

    double SVideo::IConvertFromPixelToRectangleVertical(std::int32_t APixel)
    {
        return(static_cast<double>(APixel) / static_cast<double>(FHeight));
    }

    double SVideo::IConvertFromPixelToSquare(std::int32_t APixel)
    {
        return(static_cast<double>(APixel) / static_cast<double>(FMinimum));
    }

    std::int32_t SVideo::IConvertFromRectangleToPixelHorizontal(double ARectangle)
    {
        return(static_cast<std::int32_t>(FWidth * ARectangle));
    }

    std::int32_t SVideo::IConvertFromRectangleToPixelVertical(double ARectangle)
    {
        return(static_cast<std::int32_t>(FHeight * ARectangle));
    }

    double SVideo::IConvertFromRectangleToSquareHorizontal(double ARectangle)
    {
        return(IConvertFromPixelToSquare(IConvertFromRectangleToPixelHorizontal(ARectangle)));
    }

    double SVideo::IConvertFromRectangleToSquareVertical(double ARectangle)
    {
        return(IConvertFromPixelToSquare(IConvertFromRectangleToPixelVertical(ARectangle)));
    }

    std::int32_t SVideo::IConvertFromSquareToPixel(double ASquare)
    {
        return(static_cast<std::int32_t>(FMinimum * ASquare));
    }

    double SVideo::IConvertFromSquareToRectangleHorizontal(double ASquare)
    {
        return(IConvertFromPixelToRectangleHorizontal(IConvertFromSquareToPixel(ASquare)));
    }

    double SVideo::IConvertFromSquareToRectangleVertical(double ASquare)
    {
        return(IConvertFromPixelToRectangleVertical(IConvertFromSquareToPixel(ASquare)));
    }

    void SVideo::IPostupdate()
    {
        SDL_RenderPresent(FRenderer);
    }

    SVideo::~SVideo()
    {
        FImages.clear();
        IMG_Quit();
        FFonts.clear();
        TTF_Quit();
        SDL_DestroyRenderer(FRenderer);
        SDL_DestroyWindow(FWindow);
    }
}