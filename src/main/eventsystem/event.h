#pragma once

namespace Sdl2Paint
{
    class Event
    {
    private:
        using EventList = std::list<EventCallbackHandler*>;

    private:
        bool      mIsInInvoke;
        EventList mEvents;
        EventList mDeleteEvents;
        EventList mAddEvents;

    private:
        Event           ( const Event&  ) = delete;
        Event& operator=( const Event&  ) = delete;
        Event           ( const Event&& ) = delete;
        Event& operator=(       Event&& ) = delete;

    public:
        Event();
        virtual ~Event();

    public:
        inline bool Invoke( const iEventArgument* const aEventArgument );

        template <typename TYPEEVENTHANDLER>
        inline bool Register( TYPEEVENTHANDLER* const aObserver, const bool ( TYPEEVENTHANDLER::*aCallback )( const iEventArgument* const ) );

        template <typename TYPEEVENTHANDLER>
        inline bool Unregister( TYPEEVENTHANDLER* const aObserver, const bool ( TYPEEVENTHANDLER::*aCallback )( const iEventArgument* const ) );
    };

    inline bool Event::Invoke( const iEventArgument * const aEventArgument )
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
