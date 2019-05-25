#pragma once

namespace nSdl2Paint
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