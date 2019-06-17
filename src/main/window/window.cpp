/*!
 * \file   window.cpp
 * \author Attila Krüpl
 * \date   2019/06/16
 * \info   www.krupl.com
 */

#include "stdafx.h"

using namespace nSdl2Paint::nWindow;

Window::Window()
    : mRenderer        ( nullptr              )
    , mWindow          ( nullptr              )
    , mUiEventContainer( new UiEventContainer )
{}

Window::~Window()
{
}

bool Window::OnInitialize( std::shared_ptr<UiEventContainer> aUiEventContainer )
{
    if( IS_NOT( aUiEventContainer ) )
    {
        return false;
    }

    mUiEventContainer = aUiEventContainer;

    if( IS_FAIL( SDL_Init( SDL_INIT_VIDEO ) ) )
    {
        PRINT_ERROR( SDL_GetError() );
        return false;
    }

    if( IS_FAIL( TTF_Init() ) )
    {
        PRINT_ERROR( TTF_GetError() );
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

    PrintVideoInformation();

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
    TTF_Quit();
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

std::shared_ptr<UiEventContainer> Window::GetUiEventContainer()
{
    return mUiEventContainer;
}

void Window::PrintVideoInformation()
{
    if ( mWindow )
    {
        const int   lNumVideoDrives         = SDL_GetNumVideoDrivers();
        std::cout << "Number of video drives: " << lNumVideoDrives << std::endl;
        for ( int i = 0; i < lNumVideoDrives; ++i )
        {
            const char* lVideoDriver = SDL_GetVideoDriver( i );
            std::cout << "Video driver number " << ( i + 1 ) << ": " << lVideoDriver << std::endl;
        }
        const char* lCurrentVideoDriverName = SDL_GetCurrentVideoDriver();
        std::cout << "Current video driver: " << lCurrentVideoDriverName << std::endl;

        const int   lNumVideoDisplays       = SDL_GetNumVideoDisplays();
        std::cout << "Number of video displays: " << lNumVideoDisplays << std::endl;
        for ( int i = 0; i < lNumVideoDisplays; ++i )
        {
            const char* lDisplay = SDL_GetDisplayName( i );
            std::cout << "Display number " << ( i + 1 ) << ": " << lDisplay << std::endl;

            SDL_Rect lRect{};
            const int lResult = SDL_GetDisplayBounds( i, ADDRESS_OF( lRect ) );
            if ( IS_SUCCESS( lResult ) )
            {
                std::cout << "Position (x, y): ("
                          << lRect.x
                          << ", "
                          << lRect.y
                          << "); Size (width, height): ("
                          << lRect.w
                          << ", "
                          << lRect.h
                          << ")"
                          << std::endl;
            }
            const int lNumberOfDisplayModes = SDL_GetNumDisplayModes( i );
            std::cout << "Number of display modes: " << lNumVideoDisplays << std::endl;
        }
    }
}

SDL_Rect Window::GetRect()
{
    return SDL_Rect{};
}
