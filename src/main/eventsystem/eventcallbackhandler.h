/*!
 * \file   eventcallbackhandler.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#pragma once

namespace nSdl2Paint
{
    template<typename TYPEOBSERVERCLASS>
    class EventCallbackHandler
    {
    private:
        using EventMemberCallback_type = const bool ( TYPEOBSERVERCLASS::* ) ( const iEventArgument* const );

    private:
        TYPEOBSERVERCLASS*       const mObserver;
        EventMemberCallback_type const mCallback;

    public:
        EventCallbackHandler( TYPEOBSERVERCLASS* aObserver, EventMemberCallback_type const aCallback );

    public:
        virtual const bool Call( const iEventArgument* const aEventArgument ) override;
        virtual const bool Equal( void* const aObserver, void* aCallback ) const override;
    };

    template<typename TYPEOBSERVERCLASS>
    EventCallbackHandler<TYPEOBSERVERCLASS>::EventCallbackHandler( TYPEOBSERVERCLASS*             aObserver
                                                                 , EventMemberCallback_type const aCallback )
        : mObserver( aObserver )
        , mCallback( aCallback )
    {}
}