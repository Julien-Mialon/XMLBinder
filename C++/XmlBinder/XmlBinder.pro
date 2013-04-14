#-------------------------------------------------
#
# Project created by QtCreator 2013-04-09T10:40:32
#
#-------------------------------------------------

QT       -= gui
QT       += xml

QMAKE_CXXFLAGS += -std=c++0x

TARGET = XmlBinder
TEMPLATE = lib

DEFINES += XMLBINDER_LIBRARY

SOURCES += xmlelement.cpp \
    xmlreader.cpp \
    xmlattribute.cpp \
    Interface/ibinder.cpp \
    Interface/itransformer.cpp \
    Tools/xmlattributedata.cpp \
    Binder/objectbinder.cpp \
    Binder/contentbinder.cpp \
    Transformer/qstringtransformer.cpp \
    Binder/abstractbinder.cpp \
    Tools/fieldaccess.cpp \
    Transformer/inttransformer.cpp \
    Transformer/floattransformer.cpp \
    Transformer/booltransformer.cpp \
    Transformer/chartransformer.cpp

HEADERS += xmlelement.hpp\
	XmlBinder_global.hpp \
    xmlreader.hpp \
    xmlattribute.hpp \
    Interface/ibinder.hpp \
    Interface/itransformer.hpp \
    Tools/xmlattributedata.hpp \
    Binder/objectbinder.hpp \
    Binder/contentbinder.hpp \
    Transformer/qstringtransformer.hpp \
    Binder/abstractbinder.hpp \
    Tools/fieldaccess.hpp \
    Transformer/inttransformer.hpp \
    Transformer/floattransformer.hpp \
    Transformer/booltransformer.hpp \
    Transformer/chartransformer.hpp \
    Transformer/transformers.hpp

unix:!symbian {
    maemo5 {
	target.path = /opt/usr/lib
    } else {
	target.path = /usr/lib
    }
    INSTALLS += target
}
