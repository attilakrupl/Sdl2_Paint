#include "stdafx.h"

using namespace nSdl2Paint::nWindow;

Window::Window()
    : mRenderer        ( nullptr              )
    , mWindow          ( nullptr              )
    , mUiEventContainer( new UiEventContainer )
{}

Window::~Window()
{
    delete mUiEventContainer;
    mUiEventContainer = nullptr;
}

bool Window::OnInitialize()
{
    if( IS_FAIL( SDL_Init( SDL_INIT_VIDEO ) ) )
    {
        PRINT_ERROR( SDL_GetError() );
        return false;
    }

    if( IS_NOT( SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) )
    {
        PRINT_WARNING( "Linear texture filtering not enabled!" );
    }

    mWindow = SDL_CreateWindow( "SDL2 Paint Graphical Application"
                              , SDL_WINDOWPOS_UNDEFINED
                              , SDL_WINDOWPOS_UNDEFINED
                              , SCREEN_WIDTH
                              , SCREEN_HEIGHT
                              , SDL_WINDOW_SHOWN );
    if( IS_NULL( mWindow ) )
    {
        PRINT_ERROR( SDL_GetError() );
        return false;
    }

    mRenderer = SDL_CreateRenderer( mWindow
                                  , -1
                                  , SDL_RENDERER_ACCELERATED );
    if( IS_NULL( mRenderer ) )
    {
        PRINT_ERROR( SDL_GetError() );
        return false;
    }

    int lSetColorSuccess = SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    if( IS_FAIL( lSetColorSuccess ) )
    {
        PRINT_WARNING( SDL_GetError() );
    }

    return true;
}

bool Window::OnDeinitialize()
{
    SDL_Quit();

    return true;
}

bool Window::LoadMedia()
{
    bool lSuccess = true;

    return lSuccess;
}

void Window::Close()
{
    SDL_DestroyRenderer( mRenderer );
    SDL_DestroyWindow  ( mWindow   );
    mRenderer = nullptr;
    mWindow = nullptr;

    IMG_Quit();
    SDL_Quit();
}

bool Window::Render()
{
    int lRenderDrawColorResult = SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    if( IS_FAIL( lRenderDrawColorResult ) )
    {
        PRINT_ERROR( SDL_GetError() );
        return false;
    }

    int lRenderClearResult = SDL_RenderClear( mRenderer );
    if( IS_FAIL( lRenderClearResult ) )
    {
        PRINT_ERROR( SDL_GetError() );
        return false;
    }

    SDL_RenderPresent( mRenderer );

    return true;
}