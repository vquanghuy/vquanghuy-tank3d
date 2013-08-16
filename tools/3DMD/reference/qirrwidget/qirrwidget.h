#include "qirrwidget.h"
#include <QDebug>

QirrWidget::QirrWidget(QWidget *parent) :
    QWidget(parent)
{
    device = 0;

    driverType = EDT_OPENGL;
}

QirrWidget::~QirrWidget()
{
    if ( device != 0 )
    {
        device->closeDevice();
        device->drop();
    }
}

void QirrWidget::init()
{
    if ( device != 0 )
        return;

    SIrrlichtCreationParameters params;
    params.DriverType = EDT_OPENGL;
    params.WindowId = reinterpret_cast<void*>(winId());

    qDebug() << "widget ID " << showbase << hex << winId();
    qDebug() << "win ID " << params.WindowId;

    params.WindowSize.Width = width();
    params.WindowSize.Height = height();

    device = createDeviceEx(params);

    if(device)
        camera = device->getSceneManager()->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));


    setAttribute(Qt::WA_OpaquePaintEvent);

    connect(this, SIGNAL(updateIrrlichtQuery(IrrlichtDevice*)), this, SLOT(updateIrrlicht(IrrlichtDevice*)));


    startTimer(0);
}

IrrlichtDevice* QirrWidget::getIrrlichtDevice()
{
    return device;
}

void QirrWidget::paintEvent(QPaintEvent* event)
{
    if ( device != 0 )
    {
        emit updateIrrlichtQuery(device);
    }
}

void QirrWidget::timerEvent(QTimerEvent* event)
{
    if ( device != 0 )
    {
        emit updateIrrlichtQuery(device);
    }

    event->accept();
}

void QirrWidget::resizeEvent(QResizeEvent* event)
{
    if ( device != 0 )
    {
        dimension2d<u32> widgetSize;
        widgetSize.Width = event->size().width();
        widgetSize.Height = event->size().height();
        device->getVideoDriver()->OnResize(widgetSize);

        ICameraSceneNode *cam = device->getSceneManager()->getActiveCamera();
        if (cam != 0)
        {
            cam->setAspectRatio( (f32)widgetSize.Height / (f32)widgetSize.Width );
        }
    }

    QWidget::resizeEvent(event);
}

void QirrWidget::updateIrrlicht( irr::IrrlichtDevice* device )
{
    if(device != 0)
    {
        device->getTimer()->tick();

        SColor color (255,100,101,140);

        device->getVideoDriver()->beginScene(true, true, color);

            device->getSceneManager()->drawAll();

        device->getVideoDriver()->endScene();
    }

}