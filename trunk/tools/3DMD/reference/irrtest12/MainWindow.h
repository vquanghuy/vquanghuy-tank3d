#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <irrlicht.h>

using namespace irr;
using namespace irr::video;
using namespace irr::core;
using namespace irr::scene;

class MainWindow : public QWidget
{
    Q_OBJECT

    private:
    IrrlichtDevice *m_Device;
    ISceneManager *m_Scene;
    IVideoDriver *m_Driver;

    void createIrrlichtDevice();
    void buildIrrlichtScene();
    void drawIrrlichtScene();

    public:
    MainWindow( const QString &windowTitle );

    virtual void paintEvent( QPaintEvent *event );
    virtual void resizeEvent( QResizeEvent *event );
    virtual QPaintEngine * paintEngine() const;

    public slots:
    void quit();
};

#endif // MAINWINDOW_H
