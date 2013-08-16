#ifndef QIRRLICHTWIDGET_H
#define QIRRLICHTWIDGET_H
 
#include <QDebug>
#include <QWidget>
#include <QShowEvent>
#include <QPaintEngine>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QMouseEvent>
 
#include <irrlicht.h>
 
#if linux
#include <X11/Xlib.h>
#include <QtGui/QX11Info>
#endif
 
/*!
 * \brief QIrrlichtWidget: Irrlicht Engine Widget
 *
 * This class can be used to display a Irrlicht 3D Engine powered scene in your Qt
 * application.
*/
class QIrrlichtWidget : public QWidget
{
    Q_OBJECT
 
private:
    irr::IrrlichtDevice *m_IrrDevice;
    irr::video::E_DRIVER_TYPE m_DriverType;
    irr::video::SColor m_ClearColor;
 
    int internalTimer;
 
#if linux
    // X11 specific code to disable autorepeat
    void setAutoRepeatKeys( bool mode );
#endif
 
protected:
    virtual QPaintEngine * paintEngine() const;
    virtual void resizeEvent( QResizeEvent *event );
    virtual void paintEvent( QPaintEvent *event );
    virtual void timerEvent(QTimerEvent* event);
    virtual void mousePressEvent( QMouseEvent *event );
    virtual void mouseReleaseEvent( QMouseEvent *event );
    virtual void mouseMoveEvent( QMouseEvent *event );
    virtual void keyPressEvent( QKeyEvent *event );
    virtual void keyReleaseEvent( QKeyEvent *event );
#if linux
    virtual void focusInEvent( QFocusEvent *event );
    virtual void focusOutEvent( QFocusEvent *event );
#endif
 
public:
 
    void updateScreen();
 
    void startScreenLoop();
 
    void stopScreenLoop();
 
    /*! \brief Constructor for the Widget. At least you have to specify the parent. Per default OpenGL is used
      for the rendering
      */
    QIrrlichtWidget( QWidget *parent, irr::video::E_DRIVER_TYPE driverType = irr::video::EDT_OPENGL );
    virtual ~QIrrlichtWidget();
 
    /*! \brief Retrieve the Irrlicht Device
      \returns The Irrlicht Device used in this Widget
      */
    irr::IrrlichtDevice * getIrrlichtDevice();
 
    irr::video::IVideoDriver * getIrrlichtVideo();
 
    /*! \brief Retrieve the Scene Manager
      \returns The Scene Manager used in this Widget
      */
    irr::scene::ISceneManager * getSceneManager();
 
    /*! \brief Sets the Color used to clear the screen (Background color). Default is a dark gray (0.2 0.2 0.2)
      \param color Color (RGB)
      */
    void setClearColor( const irr::video::SColorf &color );
 
    /*! \brief Set the aspect ratio of the active camera. Per default this is set to window width / window height every time the widget is resized
      \param aspect Aspect Ratio to set
      */
    void setAspectRatio( irr::f32 aspect = -1.0f );
 
    /*! \brief Initializes the Irrlicht subsystem. You have to call this after the widget has been created
      */
    void initialize();
 
public slots:
 
    // Function called in response to updateIrrlichtQuery. Renders the scene in the widget
    void updateIrrlicht(irr::IrrlichtDevice* device);
 
signals:
 
    // Signal that its time to update the frame
    void updateIrrlichtQuery(irr::IrrlichtDevice* device);
 
    /*! \brief Is emitted whenever the user presses a mouse button */
    void mousePress( QMouseEvent *event );
 
    /*! \brief Is emitted whenever the user releases a mouse button */
    void mouseRelease( QMouseEvent *event );
 
    /*! \brief Is emitted whenever the user moves the mouse. Mouse Tracking is active per default, call setMouseTracking(bool) to disable this */
    void mouseMove( QMouseEvent *event );
 
    /*! \brief Is emitted whenever the user pressed a Key */
    void keyPress( QKeyEvent *event );
 
    /*! \brief Is emitted whenever the user releases a Key */
    void keyRelease( QKeyEvent *event );
};
 
#endif // QIRRLICHTWIDGET_H