#include "stdafx.h"

int main( int argc, char** argv )
{
    Sdl2Paint::Window::Window lWindow;
    if( IS_NOT( lWindow.OnInitialize() ) )
    {
        printf( "Failed to initialize!\n" );
        return -1;
    }
    if( IS_NOT( lWindow.LoadMedia() ) )
    {
        printf( "Failed to load media!\n" );
        return -1;
    }

    Sdl2Paint::Window::EventHandler lEventHandler( &lWindow );
    if( IS_NOT( lEventHandler.RunEventLoop() ) )
    {
        PRINT_ERROR( "Event loop run into an error." );
        return -1;
    }


    return 0;
}