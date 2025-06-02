#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2main")
#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2")
#pragma comment(lib , "../SimpleDirectMediaLayer/Image/SDL2_image")
#pragma comment(lib , "../SimpleDirectMediaLayer/Mixer/SDL2_mixer")
#pragma comment(lib , "../SimpleDirectMediaLayer/TrueTypeFont/SDL2_ttf")

#include"Hope.hxx"

namespace NHope
{
    SHope::SHope()
    {
        NHope::GDebug.ICode(SDL_Init(SDL_INIT_EVERYTHING));
    }
    
    void SHope::IInitiate()
    {
        while(NHope::GKeyboard.FKeys["Escape"]->FState == "Up")
        {
            NHope::GKeyboard.IUpdate();
            NHope::GMouse.IUpdate();
            NHope::GTime.IUpdate();
            NHope::GSpace.IUpdate();
            NHope::GVideo.IUpdate();
        };
    }

    SHope::~SHope()
    {
        SDL_Quit();
    }
}

std::int32_t main(std::int32_t , char**)
{
    NHope::GHope.IInitiate();
    return(0);
}