#pragma once

namespace Sdl2Paint
{
    class EventContainer
    {
    public:
        EventContainer() = default;
        virtual ~EventContainer() = default;

    public:
        Event EventMouseMove;
    };
}