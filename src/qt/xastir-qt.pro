#-------------------------------------------------
#
# Project created by QtCreator 2010-02-24T13:21:10
#
#-------------------------------------------------

QT       += network

TARGET = xastir-qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    packetinterface.cpp \
    netinterface.cpp \
    interfacecontroldialog.cpp \
    netinterfacepropertiesdialog.cpp \
    interfacemanager.cpp \
    stationconfigurationdialog.cpp \
    stationsettings.cpp \
    symbols.cpp \
    colors.cpp \
    incomingdatadialog.cpp \
    defaultsdialog.cpp \
    timingdialog.cpp \
    coordinatesysdialog.cpp

HEADERS  += \
    xastir.h \
    packetinterface.h \
    netinterface.h \
    interfacecontroldialog.h \
    netinterfacepropertiesdialog.h \
    interfacemanager.h \
    stationconfigurationdialog.h \
    stationsettings.h \
    symbols.h \
    colors.h \
    incomingdatadialog.h \
    defaultsdialog.h \
    timingdialog.h \
    coordinatesysdialog.h

FORMS    += mainwindow.ui \
    interfacecontroldialog.ui \
    netinterfacepropertiesdialog.ui \
    stationconfigurationdialog.ui \
    incomingdatadialog.ui \
    defaultsdialog.ui \
    timingdialog.ui \
    coordinatesysdialog.ui

RESOURCES += \
    xastir.qrc
