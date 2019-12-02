/*!
 * \file   ieventcallbackhandler.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#pragma once

namespace nSdl2Paint
{
    class iEventArgument;

    class iEventCallbackHandler
    {
    public:
        virtual ~iEventCallbackHandler() = default;

    public:
        virtual const bool Call( const iEventArgument* const aEventArgument ) = 0;
        virtual const bool Equal( void* const aObserver, void* aCallback ) const = 0;
    };
}