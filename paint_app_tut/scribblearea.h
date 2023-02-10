#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QPainter>
#include <QPushButton>

//----------------------------------------------------------------
//
// Paint App Tutorial by Derek Banas (2018), created on 03/03/2022
//
//----------------------------------------------------------------
class ScribbleArea : public QWidget
{
    Q_OBJECT

public:
    ScribbleArea(QWidget *parent = 0);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setRightPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    QImage getImage();
    QPoint getPosition();
    bool isSelecting();
    bool shapeIsSelected();
    bool selectingColor();
    bool selecting;
    bool shapeSelected;
    bool fill_mode;
    bool line_mode;
    bool shape_drawn;
    bool pickingColor;
    void createShape(QMouseEvent *event);
    void select(QPoint firstSelectPoint, QPoint lastSelectPoint);
    void pickColor(QPoint colorPoint);
    void undoCall();
    void redoCall();
    void setMode(int x) { mode = x; }
    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    QColor rightPenColor() const { return myRightPenColor; }
    QColor getLastColor() const { return lastColor; }
    int penWidth() const { return myPenWidth; }
    void setChangedColor(int c);
    int getChangedColor() const { return colorSelecter; }
    void resetImageSize(QImage *image);
    void inputResize(QSize newSize); 
    void setPenType(QColor pc, QPainter *painter);
    void fillCanvas(QColor c);

    QVector <QImage> ustack;
    QVector <QImage> rstack;

    QColor myCanvasColor;
    QColor myPenColor;
    QPushButton *pentype;
    
    QString shape;

public slots:
    void clearImage();
    void print();
    void newWindow(int w, int h);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint,QColor pc);
    void resizeImage(QImage *image, const QSize &newSize); 
    void resize_Event(); 

    bool modified;
    bool line_drawn;
    bool scribbling;

    int myPenWidth;
    QColor myRightPenColor;

    QImage image;
    QColor lastColor;
    int colorSelecter;
    int mode;
    QPoint lastPoint;
    QPoint firstSelectPoint, lastSelectPoint, colorPoint;

};

#endif // SCRIBBLEAREA_H
