#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2main")
#pragma comment(lib , "../SimpleDirectMediaLayer/SDL2")
#pragma comment(lib , "../SimpleDirectMediaLayer/Image/SDL2_image")
#pragma comment(lib , "../SimpleDirectMediaLayer/Mixer/SDL2_mixer")
#pragma comment(lib , "../SimpleDirectMediaLayer/TrueTypeFont/SDL2_ttf")

#include"Hope.hpp"

#include"Hope/Keyboard/Key.hpp"

namespace NHope
{
    SHope::SHope()
    {
        GDebug.ISimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    }

    void SHope::IUpdate()
    {
        while(GKeyboard.FKeys["Escape"]->FState == "Up")
        {
            GAudio.IPreupdate();
            GDebug.IPreupdate();
            GKeyboard.IPreupdate();
            GMouse.IPreupdate();
            SDL_Event LEvent;
            while(SDL_PollEvent(&LEvent))
            {
                switch(LEvent.type)
                {
                    case(SDL_KEYDOWN):
                        GKeyboard.IPostupdate(LEvent);
                    break;
                    case(SDL_KEYUP):
                        GKeyboard.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEBUTTONDOWN):
                        GMouse.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEBUTTONUP):
                        GMouse.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEMOTION):
                        GMouse.IPostupdate(LEvent);
                    break;
                    case(SDL_MOUSEWHEEL):
                        GMouse.IPostupdate(LEvent);
                    break;
                }
            }
            GTime.IPreupdate();
            GVideo.IPreupdate();
            GInterface.IPreupdate();
            GSpace.IPreupdate();
            GSpace.IPostupdate();
            GInterface.IPostupdate();
            GVideo.IPostupdate();
            GTime.IPostupdate();
            GDebug.IPostupdate();
            GAudio.IPostupdate();
        };
    }

    SHope::~SHope()
    {
        SDL_Quit();
    }
}

std::int32_t main(std::int32_t , char**)
{
    NHope::GHope.IUpdate();
    return(0);
}