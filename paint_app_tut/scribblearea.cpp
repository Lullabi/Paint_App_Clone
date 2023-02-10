//----------------------------------------------------------------
//
// Paint App Tutorial by Derek Banas (2018), created on 03/03/2022
//
//----------------------------------------------------------------
#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif // QT_CONFIG(printdialog)
#endif // defined(QT_PRINTSUPPORT_LIB)
#include "scribblearea.h"

ScribbleArea::ScribbleArea(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    shapeSelected = false;
    pickingColor = false;
    line_mode = false;
    fill_mode = false;
    line_drawn = false;
    shape_drawn = false;
    shapeSelected = false;
    myPenWidth = 10;
    myPenColor = Qt::black;
    pentype = new QPushButton();
    pentype->setText("Round");
    myRightPenColor = Qt::red;
    myCanvasColor = Qt::white;
    mode = 0;
    resize_Event();
}

bool ScribbleArea::openImage(const QString &fileName) {
    QImage loadedImage;
    if (!loadedImage.load(fileName)) {
        return false;
    }
    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}


bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat) {
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());
    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}

QImage ScribbleArea::getImage() { return image; }

QPoint ScribbleArea::getPosition() { return lastPoint; }

bool ScribbleArea::isSelecting() { return selecting; }

bool ScribbleArea::shapeIsSelected() { return shapeSelected; }

bool ScribbleArea::selectingColor() { return pickingColor; }

void ScribbleArea::createShape(QMouseEvent *event) {
    //QColor color;
    QColor tmp;
    if ((event->buttons() & Qt::LeftButton))
    {
        tmp = penColor();
    }
    else
    {
        tmp = rightPenColor();
    }
    if (shape_drawn) {
        if (!(lastPoint == event->pos()))
        {
            undoCall();
        }
    }

    QPainter shape_image (&image);
    shape_image.setPen(QPen(tmp, myPenWidth, Qt::SolidLine,
                         Qt::FlatCap, Qt::BevelJoin));

    if (QString::compare(shape, "Circle/Oval") == 0)
    {
        QRect rectangle(lastPoint, event->pos());
        shape_image.drawEllipse(rectangle);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Semi-circle/oval") == 0)
    {
        if (lastPoint.y() >= event->pos().y())
        {
            QRectF rectangle(lastPoint, event->pos());
            int start_angle = 0;
            int span_angle = 180 * 16;
            shape_image.drawPie(rectangle, start_angle, span_angle);
            shape_drawn = true;
        }
        else
        {
            QRectF rectangle(lastPoint, event->pos());
            int start_angle = 180 * 16;
            int span_angle = 180 * 16;
            shape_image.drawPie(rectangle, start_angle, span_angle);
            shape_drawn = true;
        }
    }
    else if (QString::compare(shape, "Quarter-circle/oval") == 0)
    {
        if (event->pos().x() >= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            QRectF rectangle(lastPoint, event->pos());
            int start_angle = 270 * 16;
            int span_angle = 90 * 16;
            shape_image.drawPie(rectangle, start_angle, span_angle);
            shape_drawn = true;
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            QRectF rectangle(lastPoint, event->pos());
            int start_angle = 90 * 16;
            int span_angle = 90 * 16;
            shape_image.drawPie(rectangle, start_angle, span_angle);
            shape_drawn = true;
        }
        else if (event->pos().x() >= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            QRectF rectangle(lastPoint, event->pos());
            int start_angle = 0;
            int span_angle = 90 * 16;
            shape_image.drawPie(rectangle, start_angle, span_angle);
            shape_drawn = true;
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            QRectF rectangle(lastPoint, event->pos());
            int start_angle = 180 * 16;
            int span_angle = 90 * 16;
            shape_image.drawPie(rectangle, start_angle, span_angle);
            shape_drawn = true;
        }
    }
    else if (QString::compare(shape, "Square/Rect") == 0)
    {
        QRect rectangle(lastPoint, event->pos());
        shape_image.drawRect(rectangle);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Triangle") == 0)
    {
        QPolygon poly;
        poly << QPoint ((lastPoint.x() + event->pos().x())/2, lastPoint.y());
        poly << QPoint (lastPoint.x(), event->pos().y());
        poly << event->pos();
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Right-angled triangle") == 0)
    {
        QPolygon poly;
        poly << lastPoint;
        poly << QPoint (lastPoint.x(), event->pos().y());
        poly << event->pos();
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Rhombus") == 0)
    {
        QPolygon poly;
        poly << QPoint((lastPoint.x() + event->pos().x())/2, lastPoint.y());
        poly << QPoint(event->pos().x(), (lastPoint.y() + event->pos().y())/2);
        poly << QPoint((lastPoint.x() + event->pos().x())/2, event->pos().y());
        poly << QPoint(lastPoint.x(), (lastPoint.y() + event->pos().y())/2);
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Pentagon") == 0)
    {
        QPolygonF poly;
        if (event->pos().x() >= lastPoint.x() && event->pos().y() >= lastPoint.y()){
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.40)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.40)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.40)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.40)));
        }
        else if (event->pos().x() >= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.40)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.40)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.40)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.40)));
        }
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Hexagon") == 0)
    {
        QPolygonF poly;
        if (event->pos().x() >= lastPoint.x() && event->pos().y() >= lastPoint.y()){
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.25)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.75)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + event->pos().y())/2);
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.75)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.25)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + event->pos().y())/2);
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.25)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.75)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + event->pos().y())/2);
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.75)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.25)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + event->pos().y())/2);
        }
        else if (event->pos().x() >= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.25)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.75)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + event->pos().y())/2);
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.75)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.25)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + event->pos().y())/2);
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.25)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.75)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + event->pos().y())/2);
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.75)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.25)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + event->pos().y())/2);
        }
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Heptagon") == 0)
    {
        QPolygonF poly;
        if (event->pos().x() >= lastPoint.x() && event->pos().y() >= lastPoint.y()){
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.9375)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.25)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.705)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.29)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.0625)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.25)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.9375)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.25)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.705)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.29)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.0625)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.25)));
        }
        else if (event->pos().x() >= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.9375)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.25)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.705)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.29)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.0625)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.25)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.9375)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.25)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.705)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.29)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.0625)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.25)));
        }
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Octagon") == 0)
    {
        QPolygonF poly;
        if (event->pos().x() >= lastPoint.x() && event->pos().y() >= lastPoint.y()){
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.29)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.71)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.29)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.71)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.71)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.29)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.71)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.29)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.29)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.71)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.29)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.71)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.71)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.29)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.71)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.29)));
        }
        else if (event->pos().x() >= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.29)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.71)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.29)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.71)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.71)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.29)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.71)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.29)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.25)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.75)), lastPoint.y());
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.25)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.75)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.75)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.25)), event->pos().y());
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.75)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.25)));
        }
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Cross") == 0)
    {
        QPolygonF poly;
        if (event->pos().x() >= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
        }
        else if (event->pos().x() >= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.67)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.33)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.67)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.67)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.33)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.33)));
        }
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }
    else if (QString::compare(shape, "Star") == 0)
    {
        QPolygonF poly;
        if (event->pos().x() >= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.65)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.70)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() + event->pos().x())/2, (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.75)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.30)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.35)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.65)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.70)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() + event->pos().x())/2, (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.75)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.30)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.35)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
        }
        else if (event->pos().x() <= lastPoint.x() && event->pos().y() >= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.65)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF(event->pos().x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.70)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() + event->pos().x())/2, (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.75)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.30)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() - (std::abs(lastPoint.x() - event->pos().x())*0.35)), (lastPoint.y() + (std::abs(lastPoint.y() - event->pos().y())*0.35)));
        }
        else if (event->pos().x() >= lastPoint.x() && event->pos().y() <= lastPoint.y())
        {
            poly << QPointF((lastPoint.x() + event->pos().x())/2, lastPoint.y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.65)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF(event->pos().x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.70)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.80)), event->pos().y());
            poly << QPointF((lastPoint.x() + event->pos().x())/2, (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.75)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.20)), event->pos().y());
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.30)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.60)));
            poly << QPointF(lastPoint.x(), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
            poly << QPointF((lastPoint.x() + (std::abs(lastPoint.x() - event->pos().x())*0.35)), (lastPoint.y() - (std::abs(lastPoint.y() - event->pos().y())*0.35)));
        }
        shape_image.drawPolygon(poly);
        shape_drawn = true;
    }

    modified = true;
    int rad = (myPenWidth / 2) + 2;
    ustack.push_back(image);
    ustack.push_back(image);
    shape_image.end();
    update(QRect(lastPoint, event->pos()).normalized().adjusted(-rad, -rad, +rad, +rad));
}


void ScribbleArea::select(QPoint firstSelectPoint, QPoint lastSelectPoint) {
    QPoint tempPoint;
    for (int i = firstSelectPoint.x(); i < lastSelectPoint.x(); ++i) {
        for (int j = firstSelectPoint.y(); j < lastSelectPoint.y(); ++j) {
            tempPoint.rx() = i;
            tempPoint.ry() = j;
        }
    }
    selecting = false;
}

void ScribbleArea::pickColor(QPoint colorPoint) {
    QColor newColor;

    newColor = getImage().pixelColor(colorPoint);

    if (newColor.isValid()) {
        if (colorSelecter == 1) { setRightPenColor(newColor); }
        else { setPenColor(newColor); }
    }
    setMode(0);
    pickingColor = false;
}

void ScribbleArea::setPenColor(const QColor &newColor) {
    myPenColor = newColor;
}

void ScribbleArea::setRightPenColor(const QColor &newColor) {
    myRightPenColor = newColor;
}

void ScribbleArea::setPenWidth(int newWidth) {
    myPenWidth = newWidth;
}

void ScribbleArea::setChangedColor(int c) {
    colorSelecter = c;
}

void ScribbleArea::clearImage() {
    ustack.push_back(image);
    image.fill(myCanvasColor);
    modified = true;
    update();
    ustack.push_back(image);
}

void ScribbleArea::fillCanvas(QColor c) {
    image.fill(c);
}

void ScribbleArea::mousePressEvent(QMouseEvent *event) {
    ustack.push_back(image);
    if (shapeSelected) {
        lastPoint = event->pos();
    }
    if (shapeIsSelected() || isSelecting()) {
        firstSelectPoint = event->pos();
    } else if (selectingColor()) {
        colorPoint = event->pos();
    }

    if((event->button() == Qt::LeftButton || event->button() == Qt::RightButton) && !(line_mode) && !(fill_mode) && !(shapeSelected)) {
        lastPoint = event->pos();
        scribbling = true;
        if(event->button() == Qt::LeftButton) {
            lastColor = penColor();
        }
        else {
            lastColor = rightPenColor();
        }

        drawLineTo(event->pos(), lastColor);
    }
    else if ((event->button() == Qt::LeftButton || event->button() == Qt::RightButton) && (fill_mode))
    {
        lastPoint = event->pos();

        QColor newColor;
        newColor = getImage().pixelColor(getPosition());

        QColor tmp;
        if(event->button() == Qt::LeftButton) {
            tmp = penColor();
        }
        else {
            tmp = rightPenColor();
        }

        QPainter painter(&image);
        painter.setPen(tmp);

        QBrush brush;
        brush.setColor(tmp);
        brush.setStyle(Qt::SolidPattern);
    }
    else if ((event->button() == Qt::LeftButton || event->button() == Qt::RightButton) && (line_mode))
    {
        lastPoint = event->pos();

        QColor tmp;
        if(event->button() == Qt::LeftButton) {
            tmp = penColor();
        }
        else {
            tmp = rightPenColor();
        }

        QPainter line(&image);
    }
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event) {
    if (mode == 0) {
        if ((event->buttons() & Qt::LeftButton) && scribbling)
            drawLineTo(event->pos(), penColor());

        if ((event->buttons() & Qt::RightButton) && scribbling)
            drawLineTo(event->pos(), rightPenColor());
    }

    if (line_mode) {
        QColor tmp;
        if (event->buttons() & Qt::LeftButton)
            tmp = penColor();
        else
            tmp = rightPenColor();
        if (line_drawn && !(lastPoint == event->pos())) undoCall();
        QPainter line (&image);
        line.setPen(QPen(tmp, myPenWidth, Qt::SolidLine,
                         Qt::FlatCap, Qt::BevelJoin));
        line.drawLine(lastPoint, event->pos());
        line_drawn = true;
        modified = true;
        int rad = (myPenWidth / 2) + 2;
        ustack.push_back(image);
        ustack.push_back(image);
        line.end();
        update(QRect(lastPoint, event->pos()).normalized().adjusted(-rad, -rad, +rad, +rad));
    }

    if (shapeSelected) {
        createShape(event);
    }
}

void ScribbleArea::mouseReleaseEvent(QMouseEvent *event) {
    lastSelectPoint = event->pos();
    if (shapeIsSelected()) {
        shape_drawn = false;
        shapeSelected = false;
    } else if (isSelecting()) {
        select(firstSelectPoint, lastSelectPoint);
    } else if (selectingColor()) {
        pickColor(colorPoint);
    }

    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos(),penColor());
        scribbling = false;
    }

    if (line_mode) {
        line_drawn = false;
    }
    ustack.push_back(image);
}

void ScribbleArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void ScribbleArea::resize_Event() { 

    int newWidth = 1550; 
    int newHeight = 800; 
    resizeImage(&image, QSize(newWidth, newHeight)); 
    update(); 

} 

void ScribbleArea::newWindow(int w, int h)  {
    resizeImage(&image, QSize(w, h));
    image.fill(myCanvasColor);
    update();
}

void ScribbleArea::inputResize(QSize newSize) 
{
    resizeImage(&image, newSize);
    update();
} 

void ScribbleArea::setPenType(QColor pc, QPainter *painter) {
    if (pentype->text() == "Round") {
        painter->setPen(QPen(pc, myPenWidth, Qt::SolidLine,
                            Qt::RoundCap, Qt::RoundJoin));
    } else if (pentype->text() == "Marker") {
        painter->setPen(QPen(pc, myPenWidth, Qt::SolidLine,
                            Qt::FlatCap, Qt::BevelJoin));
    }
}

void ScribbleArea::drawLineTo(const QPoint &endPoint, QColor pc) {
    if (!rstack.isEmpty())
        rstack.clear();
    QPainter painter(&image);
    setPenType(pc, &painter);
    painter.drawLine(lastPoint, endPoint);
    modified = true;
    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void ScribbleArea::resizeImage(QImage *image, const QSize &newSize) {
    if (image->size() == newSize) {
        return;
    }

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(myCanvasColor);
    QPainter painter (&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
    ustack.push_back(*image);
    ustack.push_back(*image);
}
void ScribbleArea::undoCall() {
    int test = ustack.size();
    if (test == 0 || test == 1 || (ustack.last() == ustack.front() && test == 2)){
        return;
    }
    if (!(ustack.isEmpty())){
        if (ustack.size() == 2){
            rstack.push_front(ustack.last());
            ustack.pop_back();
        }
        else { 
            rstack.push_front(ustack.last());
            ustack.pop_back();
            ustack.pop_back();
        }
        if (image == ustack.last()){
            ustack.pop_back();
            image = ustack.last();
        }
        else
            image = ustack.last();
        update();
    }
}

void ScribbleArea::redoCall() {
    if (image == rstack.front()) {
        image = rstack[1];
        ustack.push_back(image);
        ustack.push_back(image);
        rstack.pop_front();
    }
    else {
        image = rstack.front();
        ustack.push_back(image);
        ustack.push_back(image);
        rstack.pop_front();
    }
    update();
}


void ScribbleArea::print() {
#if QT_CONFIG(printdialog)
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0, 0, image);
    }
#endif // QT_CONFIG(printdialog);
}
