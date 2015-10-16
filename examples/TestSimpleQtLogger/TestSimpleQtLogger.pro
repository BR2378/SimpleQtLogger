#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T20:06:32
#
#-------------------------------------------------

# https://github.com/Mokolea/SimpleQtLogger

# Xcode 7.0 (Qt 5.5.0, Creator 3.5.0), OS X 10.10.5
QMAKE_MAC_SDK = macosx10.11

QT += core
QT -= gui

TARGET = TestSimpleQtLogger

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS_DEBUG += -Wextra
#QMAKE_CXXFLAGS_DEBUG += -std=c++11
#QMAKE_CXXFLAGS_DEBUG += -pedantic-errors -Wc++11-long-long

INCLUDEPATH += ../..

SOURCES += main.cpp \
  task.cpp \
  ../../simpleQtLogger.cpp

HEADERS += \
  task.h \
  ../../simpleQtLogger.h
