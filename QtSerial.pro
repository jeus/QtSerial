QT += core serialport sql
QT -= gui

TARGET = QtSerial
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
HEADERS += slavethread.h \
    threadstarter.h

SOURCES += main.cpp \
slavethread.cpp \
    threadstarter.cpp

