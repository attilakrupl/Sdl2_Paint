/*!
 * \file   event.cpp
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#include "stdafx.h"

using namespace nSdl2Paint;

void Event::UnregisterVoid( void * const aObserver, void * const aCallback )
{}

Event::Event()
{}

Event::~Event()
{
    for( iEventCallbackHandler* lHandler : mEvents )
    {
        delete lHandler;
        lHandler = nullptr;
    }
    mEvents.clear();
}

bool Event::Invoke( const iEventArgument * const aEventArgument )
{
    mIsInInvoke = true;

    const bool lNoEventHandler = mEvents.empty();
    if( lNoEventHandler )
    {
        return true;
    }

    for( iEventCallbackHandler* const lHandler : mEvents )
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
