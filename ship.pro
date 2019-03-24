TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2 -lSDL2_image

SOURCES += main.cpp \
    game.cpp \
    object.cpp \
    player.cpp \
    beam.cpp \
    level.cpp

HEADERS += \
    game.h \
    object.h \
    player.h \
    beam.h \
    level.h
