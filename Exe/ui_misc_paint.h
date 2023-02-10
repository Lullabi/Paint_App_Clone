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
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Misc_Paint
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QFrame *frame;
    QMenuBar *menubar;
    QMenu *menuHello;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Misc_Paint)
    {
        if (Misc_Paint->objectName().isEmpty())
            Misc_Paint->setObjectName(QString::fromUtf8("Misc_Paint"));
        Misc_Paint->resize(818, 611);
        centralwidget = new QWidget(Misc_Paint);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 100, 32));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(229, 179, 291, 211));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
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
        pushButton->setText(QCoreApplication::translate("Misc_Paint", "PushButton", nullptr));
        menuHello->setTitle(QCoreApplication::translate("Misc_Paint", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Misc_Paint: public Ui_Misc_Paint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISC_PAINT_H
