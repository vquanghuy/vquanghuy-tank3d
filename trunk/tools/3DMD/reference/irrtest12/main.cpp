#include <QtCore>
#include "MainWindow.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );
    MainWindow *mainWindow = new MainWindow( QString( "Qt/Irrlicht" ));
    mainWindow->setVisible( true );

    app.exec();
}