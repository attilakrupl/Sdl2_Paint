#pragma once

namespace nSdl2Paint
{
    class Event
    {
    private:
        using EventList = std::list<iEventCallbackHandler*>;

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

    private:
        void UnregisterVoid( void* const aObserver, void* const aCallback );

    public:
        Event();
        virtual ~Event();

    public:
        inline bool Invoke( const iEventArgument* const aEventArgument );

        template <typename TYPEEVENTHANDLER>
        inline void Register( TYPEEVENTHANDLER* const aObserver, const bool ( TYPEEVENTHANDLER::*aCallback )( const iEventArgument* const ) );

        template <typename TYPEEVENTHANDLER>
        inline void Unregister( TYPEEVENTHANDLER* const aObserver, const bool ( TYPEEVENTHANDLER::*aCallback )( const iEventArgument* const ) );
    };

    template<typename TYPEEVENTHANDLER>
    inline void Event::Register( TYPEEVENTHANDLER* const aObserver, const bool( TYPEEVENTHANDLER::*aCallback )( const iEventArgument * const ) )
    {
        EventCallbackHandler<TYPEEVENTHANDLER>* const lEventData = new EventCallbackHandler<TYPEEVENTHANDLER>( aObserver, aCallback );
        mEvents.push_back( lEventData );
    }

    template<typename TYPEEVENTHANDLER>
    inline void Event::Unregister( TYPEEVENTHANDLER * const aObserver, const bool( TYPEEVENTHANDLER::*aCallback )( const iEventArgument * const ) )
    {
        UnregisterVoid( aObserver, &aCallback );
    }
}
