#include <QCoreApplication>

#include <XmlBinder_global.hpp>
#include <xmlelement.hpp>
#include <xmlreader.hpp>
#include "Binder/objectbinder.hpp"
#include "Binder/contentbinder.hpp"
#include "Transformer/transformers.hpp"

#include <QMetaObject>
#include <QMetaProperty>
#include <QDebug>
#include <iostream>
#include "girldata.hpp"

Q_DECLARE_METATYPE(GirlData)

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	qRegisterMetaType<GirlData>("GirlData");



	XmlElement * girl = new XmlElement("girl", new ObjectBinder("subchild", "GirlData"));
	XmlElement * name = new XmlElement("name", new ContentBinder("name", QStringTransformer::instance));
	XmlElement * age = new XmlElement("age", new ContentBinder("age", IntTransformer::instance));
	XmlElement * btrue = new XmlElement("true", new ContentBinder("btrue", BoolTransformer::instance));
	XmlElement * bfalse = new XmlElement("false", new ContentBinder("bfalse", BoolTransformer::instance));
	XmlElement * ffloat = new XmlElement("float", new ContentBinder("ffloat", FloatTransformer::instance));
	XmlElement * cchar = new XmlElement("char", new ContentBinder("cchar", CharTransformer::instance));

	girl->addChild(name);
	girl->addChild(age);
	girl->addChild(btrue);
	girl->addChild(bfalse);
	girl->addChild(ffloat);
	girl->addChild(cchar);

	girl->addChild(girl);

	try
	{

		XmlReader r(girl);
		GirlData * g = (GirlData*)(r.read("d:/3.xml"));
		g->log();
	}
	catch(QString & str)
	{
		qDebug() << "Exception : " << str;
	}

	return 0;
	//return a.exec();
}
