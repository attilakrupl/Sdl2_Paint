/*!
 * \file   eventhandler.cpp
 * \author Attila Krüpl
 * \date   2019/06/17
 * \info   www.krupl.com
 */

#include "stdafx.h"

using namespace nSdl2Paint::nWindow;

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
        if ( IS_FAIL( lError ) )
        {
            PRINT_ERROR( "Cannot get mouse state" );
        }

        PointEventArgument lPointArgument( lXMouse, lYMouse );
        const std::shared_ptr<UiEventContainer> lUiEventContainer = mUiComponent->GetUiEventContainer();
        const bool lInvokeResult = lUiEventContainer->EventMouseMove.Invoke( &lPointArgument );
        if ( IS_NOT( lInvokeResult ) )
        {
            PRINT_WARNING( "Event invokation failed" );
        }
    }
}

EventHandler::EventHandler( std::shared_ptr<iUiComponent> aUiComponent ) :
    mUiComponent( aUiComponent )
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
