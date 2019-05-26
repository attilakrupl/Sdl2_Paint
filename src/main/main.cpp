#include "stdafx.h"

int main( int argc, char** argv )
{
    std::shared_ptr<nSdl2Paint::nWindow::UiEventContainer> lUiEventContainer = std::make_shared<nSdl2Paint::nWindow::UiEventContainer>();

    nSdl2Paint::nWindow::Window lWindow;
    if( IS_NOT( lWindow.OnInitialize( lUiEventContainer ) ) )
    {
        printf( "Failed to initialize!\n" );
        return -1;
    }

    nSdl2Paint::nWindow::EventHandler lEventHandler( &lWindow );
    if( IS_NOT( lEventHandler.RunEventLoop() ) )
    {
        PRINT_ERROR( "Event loop run into an error." );
        return -1;
    }

    lWindow.Close();

    return 0;
}