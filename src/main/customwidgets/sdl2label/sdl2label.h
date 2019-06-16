#pragma once

namespace nSdl2Paint::nCustomWidgets
{
	/*!
	 * \class  SDL2_Label
	 * \brief  SDL2 based Label Widget
	 */
    class SDL2Label
    {
    public:
		SDL2Label();
        virtual ~SDL2Label() = default;

	public:
		/*!
		 * Sets the position of the Label
		 * 
		 * \param   aPosition the target position
		 * \return  the position the label has been moved to ( considers it's own size, adjusts itself into given container )
		 */
		const SDL_Point SetPosition( const SDL_Point& aPosition );

    };
}



