#-------------------------------------------------
#
# Project created by QtCreator 2020-02-29T01:04:23
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModbusTool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable dfeprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/modbustool.cpp \
        src/baseserialcomm.cpp

HEADERS += \
        inc/modbustool.h \
        inc/baseserialcomm.h

FORMS += \
        ui/modbustool.ui

# 头文件包含路径
INCLUDEPATH += inc
# ui.h输出路径
UI_DIR += ./ui
# 可执行文件.exe输出路径
DESTDIR = ./exe

#RESOURCES += \
#        res/images.qrc

