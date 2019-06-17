#pragma once

namespace nSdl2Paint::nWindow
{
    class iUiComponent : public iRenderable
    {
    public:
        virtual ~iUiComponent() = default;

    public:
        /*!
         * Returns the UI Event Container
         * 
         * \return pointer to the ui event container
         */
        virtual std::shared_ptr<UiEventContainer> GetUiEventContainer() = 0;

        /*!
         * Returns the rect of the ui component
         * 
         * \return  the rect of the ui component
         */
        virtual SDL_Rect GetRect() = 0;
    };
}