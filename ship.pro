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
    level.cpp \
    slider.cpp

HEADERS += \
    game.h \
    object.h \
    player.h \
    beam.h \
    level.h \
    slider.h

DISTFILES += \
    e_beam.png \
    e_ship.png \
    level.png \
    p_beam.png \
    p_ship.png \
    testlevel
