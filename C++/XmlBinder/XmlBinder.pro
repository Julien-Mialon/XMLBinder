#-------------------------------------------------
#
# Project created by QtCreator 2013-04-09T10:40:32
#
#-------------------------------------------------

QT       -= gui
QT       += xml

TARGET = XmlBinder
TEMPLATE = lib

DEFINES += XMLBINDER_LIBRARY

SOURCES += xmlelement.cpp \
    xmlreader.cpp

HEADERS += xmlelement.hpp\
	XmlBinder_global.hpp \
    xmlreader.hpp

unix:!symbian {
    maemo5 {
	target.path = /opt/usr/lib
    } else {
	target.path = /usr/lib
    }
    INSTALLS += target
}
