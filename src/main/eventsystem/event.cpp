#include "stdafx.h"

using namespace Sdl2Paint;

Event::Event()
{}

Event::~Event()
{
    for( EventCallbackHandler* lHandler : mEvents )
    {
        delete lHandler;
        lHandler = nullptr;
    }
    mEvents.clear();
}

inline bool Sdl2Paint::Event::Invoke( const iEventArgument * const aEventArgument )
{
    mIsInInvoke = true;

    const bool lNoEventHandler = mEvents.empty();
    if( lNoEventHandler )
    {
        return true;
    }

    for( EventCallbackHandler* const lHandler : mEvents )
    {
        const bool lCallResult = lHandler->Call( aEventArgument );
        if ( IS_NOT( lCallResult ) )
        {
            mIsInInvoke = false;
            return lCallResult;
        }
    }
    mIsInInvoke = false;

    return true;
}
