/*!
 * \file   eventhandler.h
 * \author Attila Krüpl
 * \date   2019/06/17
 * \info   www.krupl.com
 */

#pragma once

namespace nSdl2Paint::nWindow
{
    /*!
     * \class EventHandler
     * \brief the event handler class
     */
    class EventHandler
    {
    private:
        std::shared_ptr<iUiComponent> mUiComponent;                     /*!< The pointer of the event emitter UI component */

    private:
        /*!
         * Handles given event
         * 
         * \param   aEvent       the event that should be handled
         * \param   aShouldQuit  tells whether the event handler should quit
         */
        void HandleEvent(const SDL_Event* aEvent, bool& aShouldQuit);

    public:
        /*!
         * Constructor
         * 
         * \param  aUiComponent  the pointer to the event emitter
         */
        EventHandler( std::shared_ptr<iUiComponent> aUiComponent );

        /*!
         * Destructor
         */
        virtual ~EventHandler() = default;

    public:
        /*!
         * Runs event loop
         * 
         * \return true if event loop has been run successfully, false otherwise
         */
        bool RunEventLoop();
    };
}
