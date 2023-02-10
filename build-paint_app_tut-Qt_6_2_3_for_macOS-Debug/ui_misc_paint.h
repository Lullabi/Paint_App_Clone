/********************************************************************************
** Form generated from reading UI file 'misc_paint.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISC_PAINT_H
#define UI_MISC_PAINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Misc_Paint
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuHello;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Misc_Paint)
    {
        if (Misc_Paint->objectName().isEmpty())
            Misc_Paint->setObjectName(QString::fromUtf8("Misc_Paint"));
        Misc_Paint->resize(818, 600);
        centralwidget = new QWidget(Misc_Paint);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Misc_Paint->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Misc_Paint);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 818, 24));
        menuHello = new QMenu(menubar);
        menuHello->setObjectName(QString::fromUtf8("menuHello"));
        Misc_Paint->setMenuBar(menubar);
        statusbar = new QStatusBar(Misc_Paint);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Misc_Paint->setStatusBar(statusbar);

        menubar->addAction(menuHello->menuAction());

        retranslateUi(Misc_Paint);

        QMetaObject::connectSlotsByName(Misc_Paint);
    } // setupUi

    void retranslateUi(QMainWindow *Misc_Paint)
    {
        Misc_Paint->setWindowTitle(QCoreApplication::translate("Misc_Paint", "Misc_Paint", nullptr));
        menuHello->setTitle(QCoreApplication::translate("Misc_Paint", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Misc_Paint: public Ui_Misc_Paint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISC_PAINT_H
