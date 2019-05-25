#include "stdafx.h"

int main( int argc, char** argv )
{
    nSdl2Paint::Window::Window lWindow;
    if( IS_NOT( lWindow.OnInitialize() ) )
    {
        printf( "Failed to initialize!\n" );
        return -1;
    }

    nSdl2Paint::Window::EventHandler lEventHandler( &lWindow );
    if( IS_NOT( lEventHandler.RunEventLoop() ) )
    {
        PRINT_ERROR( "Event loop run into an error." );
        return -1;
    }

    lWindow.Close();

    return 0;
}