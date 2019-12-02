/*!
 * \file   uieventcontainer.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#pragma once

namespace nSdl2Paint::nWindow
{
    class UiEventContainer
    {
    public:
        UiEventContainer() = default;
        virtual ~UiEventContainer() = default;

    public:
        Event EventMouseMove;
    };
}