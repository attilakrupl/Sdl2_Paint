#pragma once

namespace Sdl2Paint::Window
{
    bool HandleRenderError( const int aRenderResult )
    {
        if( IS_FAIL( aRenderResult ) )
        {
            PRINT_ERROR( SDL_GetError() );
            return false;
        }
        return true;
    }
}