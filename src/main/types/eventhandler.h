#pragma once

namespace Sdl2Paint::Window
{
    class EventHandler
    {
    public:
        EventHandler( iRenderable* aRenderable );
        virtual ~EventHandler() = default;

    public:
        bool RunEventLoop();

    private:
        iRenderable* mRenderable;

    private:
        void HandleEvent( const SDL_Event* aEvent, bool& aShouldQuit );
    };
}
