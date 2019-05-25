#pragma once

namespace nSdl2Paint::nWindow
{
    class Window : public iRenderable
    {
    public:
        Window();
        virtual ~Window();

    public:
        bool OnInitialize();
        bool OnDeinitialize();
        void Close();

    public:
        bool LoadMedia();
        bool Render() override;

    private:
        SDL_Renderer* mRenderer;
        SDL_Window*   mWindow;

        UiEventContainer* mUiEventContainer;
    };
}
