#pragma once

namespace nSdl2Paint::nWindow
{
    class iRenderable
    {
    public:
        virtual ~iRenderable() = default;

    public:
        virtual bool Render() = 0;
    };
}