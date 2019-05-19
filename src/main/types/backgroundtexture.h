#pragma once

namespace Sdl2Paint::Window
{
    class BackgroundTexture : public iRenderable
    {
    public:
        BackgroundTexture();
        virtual ~BackgroundTexture() = default;

    public:
        virtual bool Render() override;
    };
}
