#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T13:29:56
#
#-------------------------------------------------

QT       += core gui
CONFIG += static
QT       += network widgets
QT       += network \
            xml \
            multimedia \
            multimediawidgets \
            widgets
QTPLUGIN += qtmedia_audioengine \
            qtmultimedia_m3u    \

CONFIG += static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 77x
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    albumart.cpp \
    chatdialog.cpp \
    client.cpp \
    connection.cpp \
    network-chat_plugin_import.cpp \
    peermanager.cpp \
    server.cpp \
    qaudioLevel.cpp \
    audiorecorder.cpp

HEADERS  += \
    mainwindow.h \
    albumart.h \
    chatdialog.h \
    client.h \
    connection.h \
    peermanager.h \
    server.h \
    ui_chatdialog.h \
    qaudioLevel.h \
    audiorecorder.h
FORMS    += \
    mainwindow.ui \
    chatdialog.ui \
    audiorecorder.ui

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += C:/Libraries/taglib/include
LIBS += -LC:/Libraries/taglib/lib -ltag

DISTFILES += \
    TrackList.txt

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    TrackList.txt
