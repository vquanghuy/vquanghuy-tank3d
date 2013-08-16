#include "MainWindow.h"

MainWindow::MainWindow( const QString &windowTitle )
{
    this->resize( 640, 480 );
    this->setWindowTitle( windowTitle );
    this->setAttribute( Qt::WA_PaintOnScreen, true );

    QPushButton *button = new QPushButton( this );
    button->setText( "Quit!" );
    button->move( 20, 20 );

    connect( button, SIGNAL( clicked() ), this, SLOT( quit() ));

    createIrrlichtDevice();    
}

void MainWindow::createIrrlichtDevice()
{
    dimension2d<u32> windowSize( this->geometry().width(), this->geometry().height() );

    qDebug() << "MainWindow::createIrrlichtDevice, width = " << windowSize.Width << " height = " << windowSize.Height;

    SIrrlichtCreationParameters createParams;
    createParams.WindowId = ( void * ) this->winId();

    m_Device = createDeviceEx( createParams );
    if( m_Device == 0 )
        qDebug() << "failed to create irrlicht device";

    m_Driver = m_Device->getVideoDriver();
    m_Scene = m_Device->getSceneManager();

    buildIrrlichtScene();
}

void MainWindow::buildIrrlichtScene()
{
    m_Scene->addMeshSceneNode( m_Scene->getMesh( "models/cow.x" ));
    ILightSceneNode *light = m_Scene->addLightSceneNode();
    light->setLightType( ELT_DIRECTIONAL );
    light->setRotation( vector3df( 45.0f, 45.0f, 0.0f ));
    light->getLightData().AmbientColor = SColorf( 0.2f, 0.2f, 0.2f, 1.0f );
    light->getLightData().DiffuseColor = SColorf( 0.8f, 0.8f, 0.8f, 1.0f );

    m_Scene->addCameraSceneNode( 0, vector3df( 6, 6, -6 ), vector3df() );
}

void MainWindow::paintEvent( QPaintEvent *event )
{    
    qDebug() << "MainWindow::paintEvent()";

    drawIrrlichtScene();
}

void MainWindow::resizeEvent( QResizeEvent *event )
{
    qDebug() << "MainWindow::resizeEvent()";
}

QPaintEngine * MainWindow::paintEngine() const
{
    qDebug() << "MainWindow::paintEngine()";

    return 0;
}

void MainWindow::drawIrrlichtScene()
{
    qDebug() << "MainWindow::drawIrrlichtScene()";

    m_Driver->beginScene( true, false, SColor( 255, 128, 128, 128 ));
    m_Scene->drawAll();
    m_Driver->endScene();
}

void MainWindow::quit()
{
    this->close();
}

