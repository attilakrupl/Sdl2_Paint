#pragma once

namespace nSdl2Paint::nWindow
{
    class iUiComponent : public iRenderable
    {
    public:
        virtual ~iUiComponent() = default;

    public:
        virtual std::shared_ptr<UiEventContainer> GetUiEventContainer() = 0;
    };
}