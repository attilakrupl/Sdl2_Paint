#pragma once

namespace nSdl2Paint::nWindow
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