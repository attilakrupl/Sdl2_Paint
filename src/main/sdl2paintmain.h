#pragma once

// STD

#include <list>
#include <memory>

// SDL2

#include <SDL.h>
#include <SDL_image.h>

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

// Window Includes

#include "types/events/eventarguments/pointeventargument.h"
#include "types/events/uieventcontainer.h"

#include "types/interfaces/irenderable.h"
#include "types/interfaces/iuicomponent.h"


#include "types/backgroundtexture.h"
#include "types/eventhandler.h"
#include "types/window.h"
