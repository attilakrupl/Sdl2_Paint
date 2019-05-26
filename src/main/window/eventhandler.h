#pragma once

namespace nSdl2Paint::nWindow
{
    class EventHandler
    {
    public:
        EventHandler( std::shared_ptr<iUiComponent> aUiComponent );
        virtual ~EventHandler() = default;

    public:
        bool RunEventLoop();

    private:
        std::shared_ptr<iUiComponent> mUiComponent;

    private:
        void HandleEvent( const SDL_Event* aEvent, bool& aShouldQuit );
    };
}
