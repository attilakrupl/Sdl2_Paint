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

        }
        else if( aEvent->key.keysym.sym == SDLK_s )
        {

        }
        else if( aEvent->key.keysym.sym == SDLK_ESCAPE )
        {
            aShouldQuit = true;
        }
    }
    else if( aEvent->type == SDL_MOUSEMOTION )
    {
        int lXMouse;
        int lYMouse;
        uint32_t lError = SDL_GetMouseState( &lXMouse, &lYMouse );
        int lNewSum = lXMouse + lYMouse;
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
    }
    return lQuit;
}
