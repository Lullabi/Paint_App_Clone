//
// Created by Leoked, Updated by Jonathan Ward on April 18, 2022
// Note: code for color picker created by Miroslav Bendik on Dec 19, 2012
//
#ifndef WINSIZE_H
#define WINSIZE_H

#include <QDialog>
#include <QAbstractButton>
#include <QWidget>
#include <QColor>

namespace Ui {
class winSize;
}

class winSize : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)

public:
    explicit winSize(QWidget *parent = nullptr);
    ~winSize();
    int get_w() const {
        return w;
    }
    int get_h() const {
        return h;
    }

    void set_w(int wi = 100);
    void set_h(int he = 100);

    QColor color() const {
        return m_color;
    }

signals:
    void colorChanged(QColor arg);

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void onColorChanged();

private:
    Ui::winSize *ui;
    int w = 100;
    int h = 100;
    QColor m_color;
};

#endif // WINSIZE_H
