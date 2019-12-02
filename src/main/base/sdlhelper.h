/*!
 * \file   sdlhelper.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

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