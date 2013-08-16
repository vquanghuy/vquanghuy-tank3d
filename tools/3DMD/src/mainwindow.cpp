#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	//add 3d display to mainDisplayWidget
	m_displayWidget = new QIrrlichtWidget(ui->mainDisplayWidget);
	m_displayWidget->initialize();

	m_displayWidget->setGeometry(0, 0, ui->mainDisplayWidget->width(), ui->mainDisplayWidget->height());
}

MainWindow::~MainWindow()
{
	delete m_displayWidget;
    delete ui;
}
