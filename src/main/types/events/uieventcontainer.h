#pragma once

namespace nSdl2Paint::nWindow
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