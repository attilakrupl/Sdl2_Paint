/*!
 * \file   irenderable.h
 * \author Attila Krüpl
 * \date   2019/06/17
 * \info   www.krupl.com
 */

#pragma once

namespace nSdl2Paint::nWindow
{
    /*!
     * \class iRenderable
     * \brief the interface of the renderable objects
     */
    class iRenderable
    {
    public:
        /*!
         * Destructor
         */
        virtual ~iRenderable() = default;

    public:
        /*!
         * Renders the given object
         * 
         * \return true if rendering has been successful, false otherwise
         */
        virtual bool Render() = 0;
    };
}