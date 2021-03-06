#-------------------------------------------------
#
# Project created by QtCreator 2013-04-09T10:43:56
#
#-------------------------------------------------

QT	+= core
QT	-= gui
QT	+= xml

QMAKE_CXXFLAGS += -std=c++0x

TARGET = Test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    girldata.cpp \
    testclass.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XmlBinder/release/ -lXmlBinder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XmlBinder/debug/ -lXmlBinder
else:unix: LIBS += -L$$OUT_PWD/../XmlBinder/ -lXmlBinder

INCLUDEPATH += $$PWD/../XmlBinder
DEPENDPATH += $$PWD/../XmlBinder

HEADERS += \
    girldata.hpp \
    testclass.hpp
