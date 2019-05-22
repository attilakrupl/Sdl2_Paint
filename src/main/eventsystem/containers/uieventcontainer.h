#pragma once

namespace Sdl2Paint
{
    class UiEventContainer
    {
    public:
        UiEventContainer() = default;
        virtual ~UiEventContainer() = default;

    public:
        Event EventMouseMove;
    };
}