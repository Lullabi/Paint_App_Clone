//
// Created by leoked, Updated by jward67 on April 18, 2022
// Note: code for color picker created by Miroslav Bendik on Dec 19, 2012
//
#include <QPalette>
#include "winsize.h"
#include "ui_winsize.h"

winSize::winSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::winSize)
{
    ui->setupUi(this);
    connect(ui->redSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    onColorChanged();
}

winSize::~winSize()
{
    delete ui;
}

void winSize::set_w(int wi) {
    w = wi;
}

void winSize::set_h(int he) {
    h = he;
}

void winSize::on_buttonBox_accepted() {
    set_w(ui->w_box->value());
    set_h(ui->h_box->value());
}


//void winSize::on_buttonBox_clicked(QAbstractButton *button) {
    //set_w(ui->w_box->value());
    //set_h(ui->h_box->value());

//}

void winSize::on_pushButton_2_clicked() {
    ui->w_box->setValue(ui->w_box->value() + 1);
}


void winSize::on_pushButton_clicked() {
    ui->w_box->setValue(ui->w_box->value() - 1);
}


void winSize::on_pushButton_4_clicked()
{
    ui->h_box->setValue(ui->h_box->value() + 1);
}


void winSize::on_pushButton_3_clicked()
{
    ui->h_box->setValue(ui->h_box->value() - 1);
}

void winSize::onColorChanged()
{
    m_color.setRgb(ui->redSlider->value(), ui->greenSlider->value(), ui->blueSlider->value());
    QPalette pal = ui->displayWidget->palette();
    pal.setColor(QPalette::Window, m_color);
    ui->displayWidget->setPalette(pal);
    emit colorChanged(m_color);
}
