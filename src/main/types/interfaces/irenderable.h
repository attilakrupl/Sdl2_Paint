#pragma once

namespace Sdl2Paint::Window
{
    class iRenderable
    {
    public:
        virtual ~iRenderable() = default;

    public:
        virtual bool Render( uint8_t aAlpha ) = 0;
    };
}