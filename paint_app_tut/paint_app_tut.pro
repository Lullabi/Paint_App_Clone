QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    misc_paint.cpp \
    randompoint.cpp \
    scribblearea.cpp \
    winsize.cpp

HEADERS += \
    misc_paint.h \
    randompoint.h \
    scribblearea.h \
    winsize.h

FORMS += \
    misc_paint.ui \
    winsize.ui

TRANSLATIONS += \
    paint_app_tut_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
