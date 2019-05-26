#pragma once

// STD

#include <list>

// SDL2

#include <SDL.h>
#include <SDL_image.h>

// Base

#include "base/consts.h"
#include "base/enums.h"
#include "base/macros.h"
#include "base/sdlhelper.h"

// Interfaces

#include "types/interfaces/irenderable.h"

// Event system

#include "eventsystem/interfaces/ieventcallbackhandler.h"
#include "eventsystem/interfaces/ieventargument.h"
#include "eventsystem/eventcallbackhandler.h"
#include "eventsystem/event.h"
#include "eventsystem/containers/uieventcontainer.h"

// 

#include "types/backgroundtexture.h"
#include "types/eventhandler.h"
#include "types/window.h"
