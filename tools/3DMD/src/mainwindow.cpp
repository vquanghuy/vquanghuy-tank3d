#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "manager\RenderManager.h"

#include <qfiledialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	//add 3d display to mainDisplayWidget
	m_displayWidget = new QIrrlichtWidget(ui->mainDisplayWidget);
	m_displayWidget->initialize();

	m_displayWidget->setGeometry(0, 0, ui->mainDisplayWidget->width(), ui->mainDisplayWidget->height());

	// init render manager
	new RenderManager();

	GET_RENDER_MANAGER->initialize(m_displayWidget);
	GET_RENDER_MANAGER->setClearColor(video::SColor(255,100,101,140));

	// connect mouse event
	connect(m_displayWidget, SIGNAL(mousePress( QMouseEvent *)), this, SLOT(on_mousePress( QMouseEvent *)));
	connect(m_displayWidget, SIGNAL(mouseMove( QMouseEvent *)), this, SLOT(on_mouseMove( QMouseEvent *)));
	connect(m_displayWidget, SIGNAL(mouseRelease( QMouseEvent *)), this, SLOT(on_mouseRelease( QMouseEvent *)));

	// add MainSceneNode
	scene::ISceneManager *smgr = GET_RENDER_MANAGER->getIrrlichtDevice()->getSceneManager();
	m_mainSceneNode = new MainSceneNode(smgr->getRootSceneNode(), smgr, 666);
}

MainWindow::~MainWindow()
{
	RenderManager::FreeInstance();
	delete m_displayWidget;
    delete ui;
}

/* ==========================
	HANDLE EVENT FORM MAIN WINDOW
=========================== */
void MainWindow::on_actionOpen_triggered()
{
	
}

void MainWindow::on_actionExit_triggered()
{
	exit(0);
}

void MainWindow::on_actionAdd_Model_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
}

void MainWindow::on_mousePress( QMouseEvent *event )
{
	
}

void MainWindow::on_mouseMove( QMouseEvent *event )
{
	
}

void MainWindow::on_mouseRelease( QMouseEvent *event )
{
	
}
