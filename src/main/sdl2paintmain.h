/*!
 * \file   sdl2paintmain.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#pragma once

// STD

#include <iostream>
#include <list>
#include <memory>

// SDL2

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// Base

#include "base/consts.h"
#include "base/enums.h"
#include "base/macros.h"
#include "base/sdlhelper.h"

// Event system

#include "eventsystem/interfaces/ieventcallbackhandler.h"
#include "eventsystem/interfaces/ieventargument.h"

#include "eventsystem/eventcallbackhandler.h"
#include "eventsystem/event.h"

// Custom widgets

#include "customwidgets/sdl2label/sdl2label.h"

// Window Includes

#include "window/events/eventarguments/pointeventargument.h"
#include "window/events/uieventcontainer.h"

#include "window/interfaces/irenderable.h"
#include "window/interfaces/iuicomponent.h"

#include "window/backgroundtexture.h"
#include "window/eventhandler.h"
#include "window/window.h"
