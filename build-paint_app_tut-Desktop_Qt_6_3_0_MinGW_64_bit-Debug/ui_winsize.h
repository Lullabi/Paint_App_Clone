/********************************************************************************
** Form generated from reading UI file 'winsize.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINSIZE_H
#define UI_WINSIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_winSize
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpinBox *w_box;
    QSpinBox *h_box;

    void setupUi(QDialog *winSize)
    {
        if (winSize->objectName().isEmpty())
            winSize->setObjectName(QString::fromUtf8("winSize"));
        winSize->resize(320, 240);
        buttonBox = new QDialogButtonBox(winSize);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 200, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(winSize);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 50, 30));
        pushButton = new QPushButton(winSize);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 70, 30, 30));
        pushButton_2 = new QPushButton(winSize);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 70, 30, 30));
        label_2 = new QLabel(winSize);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 120, 50, 30));
        pushButton_3 = new QPushButton(winSize);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 120, 30, 30));
        pushButton_4 = new QPushButton(winSize);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 120, 30, 30));
        pushButton_4->setCheckable(false);
        pushButton_4->setChecked(false);
        w_box = new QSpinBox(winSize);
        w_box->setObjectName(QString::fromUtf8("w_box"));
        w_box->setGeometry(QRect(140, 70, 100, 30));
        w_box->setLayoutDirection(Qt::LeftToRight);
        w_box->setWrapping(false);
        w_box->setFrame(true);
        w_box->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        w_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        w_box->setAccelerated(true);
        w_box->setKeyboardTracking(true);
        w_box->setMinimum(100);
        w_box->setMaximum(1000);
        h_box = new QSpinBox(winSize);
        h_box->setObjectName(QString::fromUtf8("h_box"));
        h_box->setGeometry(QRect(140, 120, 100, 30));
        h_box->setLayoutDirection(Qt::LeftToRight);
        h_box->setWrapping(false);
        h_box->setFrame(true);
        h_box->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        h_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        h_box->setAccelerated(true);
        h_box->setKeyboardTracking(true);
        h_box->setMinimum(100);
        h_box->setMaximum(1000);

        retranslateUi(winSize);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, winSize, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, winSize, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(winSize);
    } // setupUi

    void retranslateUi(QDialog *winSize)
    {
        winSize->setWindowTitle(QCoreApplication::translate("winSize", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("winSize", "Width:", nullptr));
        pushButton->setText(QCoreApplication::translate("winSize", "-", nullptr));
        pushButton_2->setText(QCoreApplication::translate("winSize", "+", nullptr));
        label_2->setText(QCoreApplication::translate("winSize", "Height:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("winSize", "-", nullptr));
        pushButton_4->setText(QCoreApplication::translate("winSize", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winSize: public Ui_winSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSIZE_H
