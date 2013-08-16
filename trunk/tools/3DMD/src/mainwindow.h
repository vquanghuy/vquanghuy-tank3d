#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custom_widget\QIrrlichtWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow		*ui;
	QIrrlichtWidget		*m_displayWidget;

	/* ==========================
	HANDLE EVENT FORM MAIN WINDOW
	=========================== */
private slots:
	void on_actionOpen_triggered();
	void on_actionExit_triggered();
	void on_actionAdd_Model_triggered();
};

#endif // MAINWINDOW_H
