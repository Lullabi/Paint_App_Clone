/********************************************************************************
** Form generated from reading UI file 'winsize.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winSize
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QSpinBox *w_box;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QSpinBox *h_box;
    QPushButton *pushButton_4;
    QGridLayout *gridLayout_2;
    QSpinBox *redSpinBox;
    QSpinBox *blueSpinBox;
    QSpinBox *greenSpinBox;
    QSlider *greenSlider;
    QLabel *label_4;
    QSlider *blueSlider;
    QLabel *label_3;
    QWidget *displayWidget;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *redSlider;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *winSize)
    {
        if (winSize->objectName().isEmpty())
            winSize->setObjectName(QString::fromUtf8("winSize"));
        winSize->resize(466, 298);
        gridLayout_3 = new QGridLayout(winSize);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(winSize);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(winSize);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        w_box = new QSpinBox(winSize);
        w_box->setObjectName(QString::fromUtf8("w_box"));
        w_box->setLayoutDirection(Qt::LeftToRight);
        w_box->setWrapping(false);
        w_box->setFrame(true);
        w_box->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        w_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        w_box->setAccelerated(true);
        w_box->setKeyboardTracking(true);
        w_box->setMinimum(600);
        w_box->setMaximum(1550);
        w_box->setValue(600);

        gridLayout->addWidget(w_box, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(winSize);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        label_2 = new QLabel(winSize);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(winSize);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 1, 1, 1);

        h_box = new QSpinBox(winSize);
        h_box->setObjectName(QString::fromUtf8("h_box"));
        h_box->setLayoutDirection(Qt::LeftToRight);
        h_box->setWrapping(false);
        h_box->setFrame(true);
        h_box->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        h_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        h_box->setAccelerated(true);
        h_box->setKeyboardTracking(true);
        h_box->setMinimum(600);
        h_box->setMaximum(800);

        gridLayout->addWidget(h_box, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(winSize);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setCheckable(false);
        pushButton_4->setChecked(false);

        gridLayout->addWidget(pushButton_4, 1, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        redSpinBox = new QSpinBox(winSize);
        redSpinBox->setObjectName(QString::fromUtf8("redSpinBox"));
        redSpinBox->setMaximum(255);

        gridLayout_2->addWidget(redSpinBox, 1, 3, 1, 1);

        blueSpinBox = new QSpinBox(winSize);
        blueSpinBox->setObjectName(QString::fromUtf8("blueSpinBox"));
        blueSpinBox->setMaximum(255);

        gridLayout_2->addWidget(blueSpinBox, 3, 3, 1, 1);

        greenSpinBox = new QSpinBox(winSize);
        greenSpinBox->setObjectName(QString::fromUtf8("greenSpinBox"));
        greenSpinBox->setMaximum(255);

        gridLayout_2->addWidget(greenSpinBox, 2, 3, 1, 1);

        greenSlider = new QSlider(winSize);
        greenSlider->setObjectName(QString::fromUtf8("greenSlider"));
        greenSlider->setMaximum(255);
        greenSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(greenSlider, 2, 2, 1, 1);

        label_4 = new QLabel(winSize);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        blueSlider = new QSlider(winSize);
        blueSlider->setObjectName(QString::fromUtf8("blueSlider"));
        blueSlider->setMaximum(255);
        blueSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(blueSlider, 3, 2, 1, 1);

        label_3 = new QLabel(winSize);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        displayWidget = new QWidget(winSize);
        displayWidget->setObjectName(QString::fromUtf8("displayWidget"));
        displayWidget->setMinimumSize(QSize(64, 64));
        displayWidget->setAutoFillBackground(true);

        gridLayout_2->addWidget(displayWidget, 1, 4, 3, 1);

        label_5 = new QLabel(winSize);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(winSize);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 3);

        redSlider = new QSlider(winSize);
        redSlider->setObjectName(QString::fromUtf8("redSlider"));
        redSlider->setMaximum(255);
        redSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(redSlider, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(winSize);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(winSize);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, winSize, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, winSize, qOverload<>(&QDialog::reject));
        QObject::connect(redSlider, &QSlider::valueChanged, redSpinBox, &QSpinBox::setValue);
        QObject::connect(redSpinBox, &QSpinBox::valueChanged, redSlider, &QSlider::setValue);
        QObject::connect(greenSlider, &QSlider::valueChanged, greenSpinBox, &QSpinBox::setValue);
        QObject::connect(greenSpinBox, &QSpinBox::valueChanged, greenSlider, &QSlider::setValue);
        QObject::connect(blueSlider, &QSlider::valueChanged, blueSpinBox, &QSpinBox::setValue);
        QObject::connect(blueSpinBox, &QSpinBox::valueChanged, blueSlider, &QSlider::setValue);

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
        label_4->setText(QCoreApplication::translate("winSize", "R", nullptr));
        label_3->setText(QCoreApplication::translate("winSize", "B", nullptr));
        label_5->setText(QCoreApplication::translate("winSize", "G", nullptr));
        label_6->setText(QCoreApplication::translate("winSize", "Default Canvas Color:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winSize: public Ui_winSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSIZE_H
