//----------------------------------------------------------------
//
// Paint App Tutorial by Derek Banas (2018), created on 03/03/2022
//
//----------------------------------------------------------------
#ifndef MISC_PAINT_H
#define MISC_PAINT_H

#include <QList>
#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QPixmap>
#include <QStack>
#include <QGraphicsScene>
#include <QUndoStack>
#include <QGraphicsPolygonItem>
#include <QUndoView>
#include <QObject>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QColor>
#include <QtWidgets>

class ScribbleArea;

QT_BEGIN_NAMESPACE
namespace Ui { class Misc_Paint; }
QT_END_NAMESPACE

class Misc_Paint : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)

public:
    Misc_Paint(QWidget *parent = nullptr);

    QColor color() const {
        return m_color;
   }

public slots:


protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void colorChanged(QColor arg);

private slots:
    void open();
    void save();
    void penColor();
    void penColorButton();
    void setColorButton();
    void penWidth();
    void colorPickerButton();
    void about();
    void undo();
    void redo();
    void setErase();
    void newWindow();
    void fill_tool();
    void line_tool();
    void resizeCanvas(); 
    void selectTool();
    void shapeTool();
    void penTypeTool();
    void setColorMode1();
    void setColorMode2();
    void opacityChange(int val);
    void onColorChanged();

private:
    void createActions();
    void createMenus();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    bool maybeSave();

    bool saveFile(const QByteArray &fileFormat);

    ScribbleArea *scribbleArea;
    QLabel *imageLabel;
    double scaleFactor;
    QScrollArea *scrollArea;

    QVector<QString> colors;
    const static int numButton = 20;
    QPushButton *buttons[numButton];
    QPalette colorPal[numButton];
    QPushButton *display;
    QPalette displayColor;
    QPushButton *colorOne, *colorTwo, *colorPicker, *setButton,
                *shapeToolButton, *selectToolButton, *lineToolButton;
    QLabel *redLabel, *greenLabel, *blueLabel;
    QSlider *redSlider, *greenSlider, *blueSlider;
    QWidget *displayWidget;
    QGroupBox *mainBox, *rgbColorBox, *toolBox, *penBox;
    QGridLayout *mainGrid, *grid1, *grid2, *grid3;

    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;
    QMenu *editMenu;

    QAction *openAct;
    QAction *newAct;

    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *printAct;
    QAction *clearScreenAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *undoAct;
    QAction *eraseAct;
    QAction *redoAct;
    QAction *resizeAct;
    QAction *increaseOpacity;
    QAction *decreaseOpacity;

    QColor canvasColor = Qt::white;
    QColor m_color;
    Ui::Misc_Paint *ui;

    QUndoStack *undoStack = nullptr;
    QUndoView *undoView = nullptr;

    double penOpacity = 1.0;
    double buffer = .20;

    QHBoxLayout *layout;
    QVBoxLayout *layout2;
    QGridLayout *layout3;
};
#endif // MISC_PAINT_H
