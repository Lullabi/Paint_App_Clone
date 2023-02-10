//----------------------------------------------------------------
//
// Paint App Tutorial by Derek Banas (2018), created on 03/03/2022
//
//----------------------------------------------------------------
#include <QtWidgets>
#include <QString>
#include <QVector>
#include <QPalette>
#include <QSignalMapper>

#include "scribblearea.h"
#include "misc_paint.h"
#include "ui_misc_paint.h"
#include "winsize.h"

Misc_Paint::Misc_Paint(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Misc_Paint)
{

    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);
    createActions();
    createMenus();

    setWindowTitle(tr("PaintApp"));

    resize(1550, 800);
    
    
    imageLabel = new QLabel; 
    scrollArea = new QScrollArea; 

}

void Misc_Paint::closeEvent(QCloseEvent *event) {
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void Misc_Paint::open() {
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,
               tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty()) {
            scribbleArea->openImage(fileName);
        }
    }
}

void Misc_Paint::save() {
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}

void Misc_Paint::penColor() {
    QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
    if (newColor.isValid()) {
        scribbleArea->setPenColor(newColor);
    }
}

void Misc_Paint::setColorButton() {
    QColor setColor = m_color;
    if (setColor.isValid() && scribbleArea->getChangedColor()) {
        scribbleArea->setRightPenColor(setColor);
    }
    else {
        scribbleArea->setPenColor(setColor);
    }
}
void Misc_Paint::penColorButton() {
    QPushButton *button = (QPushButton *)sender();
    QColor buttonColor = button->palette().button().color();
    if (buttonColor.isValid() && scribbleArea->getChangedColor()) {
        scribbleArea->setRightPenColor(buttonColor);
    }
    else {
        scribbleArea->setPenColor(buttonColor);
    }
}

void Misc_Paint::setColorMode1() {
    scribbleArea->setChangedColor(0);
    QColor c = scribbleArea->penColor();
    redSlider->setValue(c.red());
    greenSlider->setValue(c.green());
    blueSlider->setValue(c.blue());
}

void Misc_Paint::setColorMode2() {
    scribbleArea->setChangedColor(1);
    QColor c = scribbleArea->rightPenColor();
    redSlider->setValue(c.red());
    greenSlider->setValue(c.green());
    blueSlider->setValue(c.blue());
}

void Misc_Paint::penWidth() {
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width : "),
                                        scribbleArea->penWidth(),
                                        1, 50, 1, &ok);
    if (ok) {
        scribbleArea->setPenWidth(newWidth);
    }
}

// For Tool Button Sets:
void Misc_Paint::colorPickerButton() {
    scribbleArea->setMode(1);
    if (!scribbleArea->selectingColor()) {
      scribbleArea->pickingColor = true;
    }
}

//implementation of this really occurs in scribblearea.cpp
void Misc_Paint::selectTool() {
   if (!scribbleArea->isSelecting()) {
        scribbleArea->selecting = true;
   }
}

void Misc_Paint::shapeTool() {
    scribbleArea->line_mode = false;
    scribbleArea->shapeSelected = true;
    QStringList items;
    items << tr("Circle/Oval") << tr("Semi-circle/oval") << tr("Quarter-circle/oval")
          << tr("Square/Rect") << tr("Triangle") << tr("Right-angled triangle")
          << tr("Rhombus") << tr("Pentagon") << tr("Hexagon") << tr("Heptagon")
          << tr("Octagon") << tr("Cross") << tr("Star");
    bool ok;
    scribbleArea->shape = QInputDialog::getItem(this, tr("Choose a shape"),
                                                tr("Shape:"), items, 0, false, &ok);
}


void Misc_Paint::about() {
    QMessageBox::about(this, tr("About Scribble"),
                       tr("<p>This is an implementation of the <b>Scribble</b> example made in QT Creator"
                          " and emphasized in Derek Banas' tutorial videos."
                          "<br>It is meant to be a test on how to create a paint application for COSC 340"
                          " as well as serve as a demonstration on how to manage project development."
                          "</p>"));
}
void Misc_Paint::adjustScrollBar(QScrollBar *scrollBar, double factor) {
    scrollBar->setValue(int(factor * scrollBar->value()
                                + ((factor - 1) * scrollBar->pageStep()/2)));
}

void Misc_Paint::scaleImage(double factor) {
        scaleFactor *= factor;
        imageLabel->resize(scaleFactor * imageLabel->pixmap().size());

        adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
        adjustScrollBar(scrollArea->verticalScrollBar(), factor);
}

void Misc_Paint::undo() {
    if (scribbleArea->ustack.isEmpty()) {
        return;
    }
    else
        scribbleArea->undoCall();
}

void Misc_Paint::redo() {
    if (scribbleArea->rstack.isEmpty()) {
        return;
    }
    else
        scribbleArea->redoCall();
}

void Misc_Paint::penTypeTool() {

    QPushButton *button = (QPushButton *)sender();
    scribbleArea->pentype = button;
}

void Misc_Paint::opacityChange(int val){
    if (val == 1) {
        if (penOpacity == 1) {
            return;
        }
        else {
            QColor temp = scribbleArea->myPenColor;
            penOpacity += buffer;
            temp.setAlphaF(penOpacity);
            scribbleArea->setPenColor(temp);
        }
    }
    else {
        if (penOpacity == 0) {
            return;
        }
        else {
            QColor temp = scribbleArea->myPenColor;
            penOpacity -= buffer;
            temp.setAlphaF(penOpacity);
            scribbleArea->setPenColor(temp);
        }
    }
}

void Misc_Paint::newWindow() {
    winSize *ws= new winSize;
    QColor newColor;
    ws->show();
    ws->exec();
    if(ws->result()) {
        int w = ws->get_w();
        int h = ws->get_h();
        maybeSave();
        scribbleArea->newWindow(w,h);
        newColor = ws->color();
        canvasColor = newColor;
        if (newColor.isValid()) {
            scribbleArea->fillCanvas(newColor);
            scribbleArea->myCanvasColor = newColor;
        }
    }
}

void Misc_Paint::setErase() {
    scribbleArea->setPenColor(canvasColor);
}

void Misc_Paint::createActions() {
    openAct = new QAction(tr("&Open"), this);

    openAct->setShortcut(QKeySequence::Open);

    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    foreach(QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());

        QAction *action = new QAction(text, this);

        action->setData(format);

        connect(action, SIGNAL(triggered()), this, SLOT(save()));

        saveAsActs.append(action);
    }
    printAct = new QAction(tr("&Print..."), this);
    connect(printAct, SIGNAL(triggered()), scribbleArea, SLOT(print()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcut(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    penColorAct = new QAction(tr("&Pen Color..."), this);
    connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));

    penWidthAct = new QAction(tr("Pen &Width..."), this);
    connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

    clearScreenAct = new QAction(tr("&Clear Screen..."), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()), scribbleArea, SLOT(clearImage()));

    aboutAct = new QAction(tr("&About..."), this);
    connect(aboutAct, SIGNAL(triggered()), SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt..."), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    undoAct = new QAction(tr("Undo"), this);
    undoAct->setShortcut(tr("Ctrl+z"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(tr("Redo"), this);
    redoAct->setShortcut(tr("Ctrl+y"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

    eraseAct = new QAction(tr("Eraser Tool"), this);
    connect(eraseAct, SIGNAL(triggered()), this, SLOT(setErase()));

    increaseOpacity = new QAction(tr("Increase Opacity"), this);
    increaseOpacity->setShortcut(tr("Ctrl+Shift+="));
    connect(increaseOpacity,  &QAction::triggered, this, [this]{ opacityChange(1); });

    decreaseOpacity = new QAction(tr("Decrease Opacity"), this);
    decreaseOpacity->setShortcut(tr("Ctrl+-"));
    connect(decreaseOpacity,  &QAction::triggered, this, [this]{ opacityChange(0); });

    newAct = new QAction(tr("New file"), this);
    connect(newAct, SIGNAL(triggered()), this, SLOT(newWindow()));
    
    resizeAct = new QAction(tr("Resize Canvas"), this); 
    connect(resizeAct, SIGNAL(triggered()), this, SLOT(resizeCanvas())); 
}

void Misc_Paint::createMenus() {
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach(QAction *action, saveAsActs)
        saveAsMenu->addAction(action);

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addAction(resizeAct); 
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    editMenu = new QMenu(tr("&Edit"), this);
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addAction(eraseAct);
    editMenu->addAction(increaseOpacity);
    editMenu->addAction(decreaseOpacity);


    for (int i = 0; i < numButton; ++i) {
        buttons[i] = new QPushButton();
        colorPal[i] = buttons[i]->palette();
    }
    colorPal[0].setColor(QPalette::Button, QColor(Qt::red));
    colorPal[1].setColor(QPalette::Button, QColor(Qt::blue));
    colorPal[2].setColor(QPalette::Button, QColor(QColorConstants::Svg::mediumpurple));
    colorPal[3].setColor(QPalette::Button, QColor(Qt::black));
    colorPal[4].setColor(QPalette::Button, QColor(Qt::green));
    colorPal[5].setColor(QPalette::Button, QColor(Qt::yellow));
    colorPal[6].setColor(QPalette::Button, QColor(QColorConstants::Svg::aqua));
    colorPal[7].setColor(QPalette::Button, QColor(QColorConstants::Svg::fuchsia));
    colorPal[8].setColor(QPalette::Button, QColor(QColorConstants::Svg::saddlebrown));
    colorPal[9].setColor(QPalette::Button, QColor(QColorConstants::Svg::darkgreen));
    colorPal[10].setColor(QPalette::Button, QColor(QColorConstants::Svg::deepskyblue));
    colorPal[11].setColor(QPalette::Button, QColor(QColorConstants::Svg::gray));
    colorPal[12].setColor(QPalette::Button, QColor(QColorConstants::Svg::goldenrod));
    colorPal[13].setColor(QPalette::Button, QColor(QColorConstants::Svg::lime));
    colorPal[14].setColor(QPalette::Button, QColor(Qt::white));
    colorPal[15].setColor(QPalette::Button, QColor(QColorConstants::Svg::orangered));
    colorPal[16].setColor(QPalette::Button, QColor(QColorConstants::Svg::powderblue));
    colorPal[17].setColor(QPalette::Button, QColor(QColorConstants::Svg::pink));
    colorPal[18].setColor(QPalette::Button, QColor(QColorConstants::Svg::peru));
    colorPal[19].setColor(QPalette::Button, QColor(QColorConstants::Svg::orange));

    layout3 = new QGridLayout(scribbleArea);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);
    menuBar()->addMenu(editMenu);

    // adding all the default color buttons
    for (int i = 0; i < numButton; ++i) {
        buttons[i]->setAutoFillBackground(true);
        buttons[i]->setPalette(colorPal[i]);
        buttons[i]->setFlat(true);
        buttons[i]->setFixedWidth(20);
        connect(buttons[i], SIGNAL(released()), this, SLOT(penColorButton()));
        layout3->addWidget(buttons[i], 0, i);
    }

    // Color 1 Button
    colorOne = new QPushButton();
    colorOne->setText("C1");
    colorOne->setFixedWidth(30);
    connect(colorOne, SIGNAL(pressed()), this, SLOT(setColorMode1()));

    // Color 2 Button
    colorTwo = new QPushButton();
    colorTwo->setText("C2");
    colorTwo->setFixedWidth(30);
    connect(colorTwo, SIGNAL(pressed()), this, SLOT(setColorMode2()));

    // For Tool Buttons
    // color picker
    colorPicker = new QPushButton();
    colorPicker->setText("Color Picker");
    colorPicker->setFixedWidth(90);
    connect(colorPicker, SIGNAL(pressed()), this, SLOT(colorPickerButton()));

    //shape tool
    shapeToolButton = new QPushButton();
    shapeToolButton->setText("Shape");
    shapeToolButton->setFixedWidth(60);
    connect(shapeToolButton, SIGNAL(pressed()), this, SLOT(shapeTool()));

    //select tool
    selectToolButton = new QPushButton();
    selectToolButton->setText("Select");
    selectToolButton->setFixedWidth(50);
    connect(selectToolButton, SIGNAL(pressed()), this, SLOT(selectTool()));

    //line tool
    lineToolButton = new QPushButton();
    lineToolButton->setText("Line");
    lineToolButton->setFixedWidth(40);
    connect(lineToolButton, SIGNAL(pressed()), this, SLOT(line_tool()));
    
    // RGB Sliders:
    redSlider = new QSlider(Qt::Horizontal);
    redSlider->setRange(0, 255);
    redLabel = new QLabel();
    redLabel->setText("R");

    greenSlider = new QSlider(Qt::Horizontal);
    greenSlider->setRange(0, 255);
    greenLabel = new QLabel();
    greenLabel->setText("G");

    blueSlider = new QSlider(Qt::Horizontal);
    blueSlider->setRange(0, 255);
    blueLabel = new QLabel();
    blueLabel->setText("B");

    setButton = new QPushButton();
    setButton->setText("Set");
    setButton->setFixedWidth(50);
    connect(setButton, SIGNAL(pressed()), this, SLOT(setColorButton()));

    // Used to display new color of pen right beside RGB sliders
    display = new QPushButton;
    displayColor = display->palette();
    displayColor.setColor(QPalette::Button, QColor(Qt::black));
    display->setAutoFillBackground(true);
    display->setPalette(displayColor);
    display->setFlat(true);
    display->setFixedSize(QSize(60, 60));
    connect(redSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(greenSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect(blueSlider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));

    // Group Box Test:
    mainBox = new QGroupBox();
    mainGrid = new QGridLayout;

    rgbColorBox = new QGroupBox(tr("RGB Pen Color:"));
    grid1 = new QGridLayout;
    grid1->addWidget(redLabel, 0, 0);
    grid1->addWidget(greenLabel, 1, 0);
    grid1->addWidget(blueLabel, 2, 0);
    grid1->addWidget(redSlider, 0, 1);
    grid1->addWidget(greenSlider, 1, 1);
    grid1->addWidget(blueSlider, 2, 1);
    grid1->addWidget(setButton, 2, 2);
    grid1->addWidget(display, 0, 2, 2, 2);
    rgbColorBox->setLayout(grid1);
    mainGrid->addWidget(rgbColorBox, 0, 0);

    toolBox = new QGroupBox(tr("Tools:"));
    grid2 = new QGridLayout;
    grid2->addWidget(colorPicker, 0, 0);
    grid2->addWidget(lineToolButton, 0, 1);
    grid2->addWidget(selectToolButton, 1, 0);
    grid2->addWidget(shapeToolButton, 1, 1);
    toolBox->setLayout(grid2);
    mainGrid->addWidget(toolBox, 1, 0);

    int numPenTypes = 2;
    QPushButton *pentypes[numPenTypes];
    for (int i = 0; i < numPenTypes; ++i) {
        pentypes[i] = new QPushButton();
        pentypes[i]->setFixedWidth(75);
        connect(pentypes[i], SIGNAL(pressed()), this, SLOT(penTypeTool()));
    }
    pentypes[0]->setText("Round");
    pentypes[1]->setText("Marker");

    QLabel *pentypenames = new QLabel();
    pentypenames->setText("Pen Types: ");
    pentypenames->setFixedWidth(75);

    penBox = new QGroupBox(tr("Pen Types:"));
    grid3 = new QGridLayout;
    grid3->addWidget(colorOne, 0, 0);
    grid3->addWidget(colorTwo, 1, 0);
    grid3->addWidget(pentypes[0], 0, 1);
    grid3->addWidget(pentypes[1], 1, 1);
    penBox->setLayout(grid3);
    mainGrid->addWidget(penBox, 2, 0);

    mainBox->setLayout(mainGrid);
    layout3->addWidget(mainBox, 1, 0, 1, 8);

    //setting alignment of buttons
    layout3->setAlignment(Qt::AlignTop);

}


void Misc_Paint::fill_tool()
{
    if (scribbleArea->fill_mode == true)
    {
        scribbleArea->fill_mode = false;
    }
    else
    {
        scribbleArea->fill_mode = true;
        scribbleArea->line_mode = false;
    }

}

void Misc_Paint::onColorChanged() {
    m_color.setRgb(redSlider->value(), greenSlider->value(), blueSlider->value());
    QPalette pal = display->palette();
    pal.setColor(QPalette::Button, m_color);
    display->setPalette(m_color);
    emit colorChanged(m_color);
}

void Misc_Paint::line_tool()
{
    if (scribbleArea->line_mode == true)
    {
        scribbleArea->line_mode = false;
    }
    else
    {
        scribbleArea->line_mode = true;
        scribbleArea->fill_mode = false;
    }
}

void Misc_Paint::resizeCanvas() 
{ 

    bool ok; 
    int newWidth = QInputDialog::getInt(this, tr("Resize Width"),
                                        tr("Select canvas width (in pixels) : "),
                                        width(), 1, 1550, 1, &ok); 
    int newHeight = QInputDialog::getInt(this, tr("Resize Height"),
                                         tr("Select canvas height (in pixels) : "),
                                         height(), 1, 800, 1, &ok); 
    scribbleArea->inputResize(QSize(newWidth, newHeight)); 
    imageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); 
    scrollArea->setWidget(imageLabel); 
    scrollArea->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); 
} 


bool Misc_Paint::maybeSave() {
    if (scribbleArea->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Scribble"),
                                   tr("The image has been modified.\n"
                                      "Do you want to save your changes?"),
                                   QMessageBox::Save | QMessageBox::Discard |
                                   QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            return saveFile("png");
        } else if (ret == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

bool Misc_Paint::saveFile(const QByteArray &fileFormat) {
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    initialPath,
                                                    tr("%1 Files (*.%2);; All Files(*)")
                                                    .arg(QString::fromLatin1(fileFormat.toUpper()),
                                                    QString::fromLatin1(fileFormat)));
    if (fileName.isEmpty()) {
        return false;
    } else {
        return scribbleArea->saveImage(fileName, fileFormat.constData());
    }
}
