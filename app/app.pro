TEMPLATE = app
TARGET = app
INCLUDEPATH += ../lib/

SOURCES += main.c

QT -= gui core
CONFIG += console
LIBS += -L../lib -lqusscore
