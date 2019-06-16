/*!
 * \file   window.h
 * \author Attila Krüpl
 * \date   2019/06/16
 * \info   www.krupl.com
 */
 
#pragma once

namespace nSdl2Paint::nWindow
{
    /*!
     * \class  Window
     * \brief  An Sdl2 Window implementation
     */
    class Window : public iUiComponent
    {
    private:
        SDL_Renderer*                     mRenderer;            /*!< The renderer           */
        SDL_Window*                       mWindow;              /*!< The window             */

        std::shared_ptr<UiEventContainer> mUiEventContainer;    /*!< The ui event container */

    private:
        /*!
         * Prints all Video related information available through SDL_video
         */
        void PrintVideoInformation();

    public:
        /*!
         * Constructor
         */
        Window();

        /*!
         * Destructor
         */
        virtual ~Window();

    public:
        /*!
         * Initializes the window
         * 
         * \param  aUiEventContainer  the UI event container
         * \return true if succeeded, false otherwise
         */
        bool OnInitialize( std::shared_ptr<UiEventContainer> aUiEventContainer );

        /*!
         * Deinitializes the window
         *
         * \return true if succeeded, false otherwise
         */
        bool OnDeinitialize();

        /*!
         * Closes the window
         */
        void Close();

    public:
        /*!
         * Loads Media
         *
         * \return  true if media has been loaded successfully, false otherwise
         */
        bool LoadMedia();

        /*!
         * Renders window
         *
         * \return  true if rendering has been successful, false otherwise
         */
        virtual bool Render() override;

    public:
        /*!
         * Returns Ui Event container
         * 
         * \return the Ui Event Container
         */
        virtual std::shared_ptr<UiEventContainer> GetUiEventContainer() override;
    };
}
