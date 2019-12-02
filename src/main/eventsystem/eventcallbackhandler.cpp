/*!
 * \file   eventcallbackhandler.cpp
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#include "stdafx.h"

using namespace nSdl2Paint;

template<typename TYPEOBSERVERCLASS>
const bool EventCallbackHandler<TYPEOBSERVERCLASS>::Call( const iEventArgument * const aEventArgument )
{
    const bool lResult = ( mObserver->*mCallback )( aEventArgument );
    return lResult;
}

template<typename TYPEOBSERVERCLASS>
const bool EventCallbackHandler<TYPEOBSERVERCLASS>::Equal( void * const aObserver
                                                         , void *       aCallback ) const
{
    EventMemberCallback_type* const lCallback = static_cast<EventMemberCallback_type* const>( aCallback );

    const bool lObserverEqual = ( mObserver == aObserver  );
    const bool lCallbackEqual = ( mCallback == *lCallback );

    return ( lObserverEqual && lCallbackEqual );
}
