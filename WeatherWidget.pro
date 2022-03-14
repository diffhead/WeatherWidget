TEMPLATE = app

TARGET = widget

DESTDIR = ./dist

SOURCES += ./src/main.cpp \
           ./src/classes/ApplicationHandler.cpp \
           ./src/classes/ApplicationWindow.cpp \
           ./src/classes/ApplicationConfig.cpp \
           ./src/classes/WeatherApiResponse.cpp

INCLUDEPATH += ./src ./src/classes

QT += widgets network gui
