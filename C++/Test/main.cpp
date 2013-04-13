#include <QCoreApplication>

#include <XmlBinder_global.hpp>
#include <xmlelement.hpp>
#include <xmlreader.hpp>
#include "Binder/objectbinder.hpp"
#include "Binder/contentbinder.hpp"
#include "Transformer/qstringtransformer.hpp"

#include <QMetaObject>
#include <QMetaProperty>

#include <iostream>
#include "girldata.hpp"

Q_DECLARE_METATYPE(GirlData)

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	qRegisterMetaType<GirlData>("GirlData");



	XmlElement * girl = new XmlElement("girl", new ObjectBinder("", "GirlData"));
	XmlElement * name = new XmlElement("name", new ContentBinder("name", QStringTransformer::instance));
	XmlElement * age = new XmlElement("age", new ContentBinder("age", QStringTransformer::instance));

	girl->addChild(name);
	girl->addChild(age);

	XmlReader r(girl);
	GirlData * g = (GirlData*)(r.read("d:/3.xml"));
	g->log();

	return a.exec();
}
