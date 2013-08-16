/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionAdd_Model;
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *mainDisplayWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuModel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionAdd_Model = new QAction(MainWindow);
        actionAdd_Model->setObjectName(QStringLiteral("actionAdd_Model"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainDisplayWidget = new QWidget(centralWidget);
        mainDisplayWidget->setObjectName(QStringLiteral("mainDisplayWidget"));
        mainDisplayWidget->setGeometry(QRect(0, 0, 601, 581));
        mainDisplayWidget->setAutoFillBackground(false);
        mainDisplayWidget->setStyleSheet(QStringLiteral("background-color: rgb(85, 85, 225);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuModel = new QMenu(menuBar);
        menuModel->setObjectName(QStringLiteral("menuModel"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuModel->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuModel->addAction(actionAdd_Model);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3D Map Design", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionAdd_Model->setText(QApplication::translate("MainWindow", "Add Model", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuModel->setTitle(QApplication::translate("MainWindow", "Model", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
