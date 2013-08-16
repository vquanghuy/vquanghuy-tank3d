#include "QIrrlichtWidget.h"

// ####################################################################
// PROTECTED MEMBERS
// ####################################################################
 
QPaintEngine * QIrrlichtWidget::paintEngine() const
{
    qDebug() << "QIrrlichtWidget::paintEngine";
 
    return 0;
}
 
void QIrrlichtWidget::updateScreen()
{
   this->paintEvent( 0 );
}
 
void QIrrlichtWidget::resizeEvent( QResizeEvent *event )
{
    qDebug() << "QIrrlichtWidget::resizeEvent";
 
    if( m_IrrDevice == 0 )
        return;
 
    int newWidth = event->size().width();
    int newHeight = event->size().height();
 
    m_IrrDevice->getVideoDriver()->OnResize( irr::core::dimension2d<irr::u32>( newWidth, newHeight ));
 
    setAspectRatio();
 
    QWidget::resizeEvent(event);
}
 
void QIrrlichtWidget::paintEvent( QPaintEvent *event )
{
    qDebug() << "QIrrlichtWidget::paintEvent";
 
    emit updateIrrlichtQuery(m_IrrDevice);
 
}
 
void QIrrlichtWidget::mousePressEvent( QMouseEvent *event )
{
    emit( mousePress( event ));
}
 
void QIrrlichtWidget::mouseReleaseEvent( QMouseEvent *event )
{
    emit( mouseRelease( event ));
}
 
void QIrrlichtWidget::mouseMoveEvent( QMouseEvent *event )
{
    emit( mouseMove( event ));
}
 
void QIrrlichtWidget::keyPressEvent( QKeyEvent * event )
{
    emit( keyPress( event ));
}
 
void QIrrlichtWidget::keyReleaseEvent( QKeyEvent *event )
{
    emit( keyRelease( event ));
}
 
// ####################################################################
// PUBLIC MEMBERS
// ####################################################################
 
QIrrlichtWidget::QIrrlichtWidget( QWidget *parent, irr::video::E_DRIVER_TYPE driverType ) : QWidget( parent )
{
    qDebug() << "QIrrlichtWidget::ctor()";
 
    setAttribute( Qt::WA_PaintOnScreen, true );
    setAttribute( Qt::WA_OpaquePaintEvent, true );
    setMouseTracking( true );
    setFocusPolicy( Qt::ClickFocus );
    setFocus( Qt::OtherFocusReason );
 
    m_IrrDevice = 0;
    m_DriverType = driverType;
 
    setClearColor( irr::video::SColorf( 0.2f, 0.2f, 0.2f ));
}
 
QIrrlichtWidget::~QIrrlichtWidget()
{
    qDebug() << "QIrrlichtWidget::dtor()";
 
    if( m_IrrDevice != 0 )
        m_IrrDevice->drop();
}
 
irr::IrrlichtDevice * QIrrlichtWidget::getIrrlichtDevice()
{
    qDebug() << "QIrrlichtWidget::getIrrlichtDevice()";
 
    if( m_IrrDevice != 0 )
        return m_IrrDevice;
 
    throw( "Irrlicht device has not been initialized");
}
 
irr::video::IVideoDriver * QIrrlichtWidget::getIrrlichtVideo()
{
    qDebug() << "QIrrlichtWidget::getIrrlichtDevice()";
 
    if( m_IrrDevice != 0 )
        return m_IrrDevice->getVideoDriver();
 
    throw( "Irrlicht device has not been initialized");
}
 
irr::scene::ISceneManager * QIrrlichtWidget::getSceneManager()
{
    qDebug() << "QIrrlichtWidget::getSceneManager";
 
    if( m_IrrDevice != 0 )
        return m_IrrDevice->getSceneManager();
 
    throw( "Irrlicht device has not been initialized" );
}
 
void QIrrlichtWidget::setClearColor( const irr::video::SColorf &color )
{
    m_ClearColor = color.toSColor();
}
 
void QIrrlichtWidget::setAspectRatio( irr::f32 aspect )
{
    qDebug() << "QIrrlichtWidget::setAspectRatio";
 
    if( m_IrrDevice == 0 )
        return;
 
    irr::f32 newAspectRatio;
    if( aspect < 0 ) // Automatic
    {
        irr::core::dimension2d<irr::u32> screenSize = m_IrrDevice->getVideoDriver()->getScreenSize();
        newAspectRatio = ( irr::f32 ) screenSize.Width / ( irr::f32 ) screenSize.Height;
    }
    else
        newAspectRatio = aspect;
 
    // Set Aspect for active Camera
    irr::scene::ISceneManager *mgr = getSceneManager();

	scene::ICameraSceneNode *camera = mgr->getActiveCamera();

	if (camera)
		camera->setAspectRatio( newAspectRatio );
}
 
void QIrrlichtWidget::initialize()
{
    qDebug() << "QIrrlichtWidget::init";
 
    if( m_IrrDevice != 0 )
        return;
 
    // Create the Irrlicht device if this is the first time we are being shown
    irr::SIrrlichtCreationParameters createParams;
    createParams.DriverType = m_DriverType;
    createParams.WindowSize = irr::core::dimension2d<irr::u32>( size().width(), size().height() );
    createParams.EventReceiver = 0;
    createParams.Stencilbuffer = true;
    createParams.IgnoreInput = true;
 
    // Window ID for creating the native rendering context
    createParams.WindowId = ( void * ) winId();
 
    qDebug() << "   render size           = " << createParams.WindowSize.Width << " x " << createParams.WindowSize.Height;
    qDebug() << "   native window ID      = " << createParams.WindowId;
 
    if(( m_IrrDevice = irr::createDeviceEx( createParams )) == 0 )
        throw( "failed to create Irrlicht device" );
 
	m_IrrCamera = m_IrrDevice->getSceneManager()->addCameraSceneNode(0, core::vector3df(0,30,-40), core::vector3df(0,5,0));
 
    connect(this, SIGNAL(updateIrrlichtQuery(irr::IrrlichtDevice*)), this, SLOT(updateIrrlicht(irr::IrrlichtDevice*)));
 
    //startScreenLoop(); 
}
 
void QIrrlichtWidget::timerEvent(QTimerEvent* event)
{
 
    emit updateIrrlichtQuery(m_IrrDevice);
}
 
 
void QIrrlichtWidget::updateIrrlicht( irr::IrrlichtDevice* device )
{ 
    if( device == 0 )
        return;
 
    // Draw everything (Scene and GUI)
    device->getVideoDriver()->beginScene( true, true, m_ClearColor );
    device->getTimer()->tick();
    device->getSceneManager()->drawAll();
    device->getVideoDriver()->endScene();
}
 
void QIrrlichtWidget::startScreenLoop()
{
    if(internalTimer != 0)
        qDebug() << "Timer already started";
 
    // Start a timer. A timer with setting 0 will update as often as possible.
    internalTimer = startTimer(0);
}
 
void QIrrlichtWidget::stopScreenLoop()
{
    if(internalTimer == 0)
        qDebug() << "Timer already stoped";
 
    killTimer( internalTimer );
    internalTimer = 0;
}