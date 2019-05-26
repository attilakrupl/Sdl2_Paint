#pragma once

namespace nSdl2Paint::nWindow
{
    class Window : public iUiComponent
    {
    private:
        SDL_Renderer*                     mRenderer;
        SDL_Window*                       mWindow;

        std::shared_ptr<UiEventContainer> mUiEventContainer;

    public:
        Window();
        virtual ~Window();

    public:
        bool OnInitialize( std::shared_ptr<UiEventContainer> aUiEventContainer );
        bool OnDeinitialize();
        void Close();

    public:
        bool LoadMedia();
        virtual bool Render() override;

    public:
        virtual std::shared_ptr<UiEventContainer> GetUiEventContainer() override;
    };
}
