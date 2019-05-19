#pragma once

namespace Sdl2Paint::Window
{
    class Window : public iRenderable
    {
    public:
        Window();
        virtual ~Window() = default;

    public:
        bool OnInitialize();
        bool OnDeinitialize();
        void Close();

    public:
        bool LoadMedia();
        bool Render( uint8_t aAlpha ) override;

    private:
        SDL_Renderer* mRenderer;
        SDL_Window*   mWindow;
    };
}
