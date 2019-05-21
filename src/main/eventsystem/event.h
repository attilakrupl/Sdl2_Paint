#pragma once

namespace Sdl2Paint
{
    class Event
    {
    public:
        inline bool Invoke( const iEventArgument* const aEventArgument );

        template <typename TYPEEVENTHANDLER>
        inline bool Register( TYPEEVENTHANDLER* const aObserver, const bool ( TYPEEVENTHANDLER::*aCallback )( const iEventArgument* const ) );

        template <typename TYPEEVENTHANDLER>
        inline bool Unregister( TYPEEVENTHANDLER* const aObserver, const bool ( TYPEEVENTHANDLER::*aCallback )( const iEventArgument* const ) );
    };

    bool Sdl2Paint::Event::Invoke( const iEventArgument * const aEventArgument )
    {
        return false;
    }

    template<typename TYPEEVENTHANDLER>
    inline bool Event::Register( TYPEEVENTHANDLER * const aObserver, const bool( TYPEEVENTHANDLER::* aCallback )( const iEventArgument * const ) )
    {
        return false;
    }

    template<typename TYPEEVENTHANDLER>
    inline bool Event::Unregister( TYPEEVENTHANDLER * const aObserver, const bool( TYPEEVENTHANDLER::* aCallback )( const iEventArgument * const ) )
    {
        return false;
    }
}
