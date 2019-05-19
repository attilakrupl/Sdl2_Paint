#include "stdafx.h"

using namespace Sdl2Paint::Window;

static Uint8 gColorComponentMAX   = 255;
static Uint8 gGREENMAX = 255;
static Uint8 gBLUEMAX  = 255;
static Uint8 gALPHAMAX = 255;

void EventHandler::HandleEvent( const SDL_Event* aEvent, bool& aShouldQuit )
{
    if( aEvent->type == SDL_QUIT )
    {
        aShouldQuit = true;
    }
    else if( aEvent->type == SDL_KEYDOWN )
    {
        if( aEvent->key.keysym.sym == SDLK_w )
        {
            if( gALPHAMAX + 32 > 255 )
            {
                gALPHAMAX = 255;
            }
            else
            {
                gALPHAMAX += 32;
            }
        }
        else if( aEvent->key.keysym.sym == SDLK_s )
        {
            if( gALPHAMAX - 32 < 0 )
            {
                gALPHAMAX = 0;
            }
            else
            {
                gALPHAMAX -= 32;
            }
        }
        else if( aEvent->key.keysym.sym == SDLK_ESCAPE )
        {
            aShouldQuit = true;
        }
    }
}

EventHandler::EventHandler( iRenderable* aRenderable ) :
    mRenderable( aRenderable )
{}

bool EventHandler::RunEventLoop()
{
    bool      lQuit = false;
    SDL_Event lEvent;

    while( !lQuit )
    {
        while ( SDL_PollEvent( &lEvent ) != 0 )
        {
            HandleEvent( &lEvent, lQuit );
        }
        if ( !mRenderable->Render( gALPHAMAX ) )
        {
            PRINT_ERROR( "Failed to update window." );
            return false;
        }
    }
    return lQuit;
}
