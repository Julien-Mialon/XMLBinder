#include <QCoreApplication>

#include <XmlBinder_global.hpp>
#include <xmlelement.hpp>
#include <xmlreader.hpp>
#include "Binder/objectbinder.hpp"
#include "Binder/contentbinder.hpp"
#include "Binder/qlistbinder.hpp"
#include "Transformer/transformers.hpp"
#include "Tools/fieldaccess.hpp"
#include <xmlwriter.hpp>

#include <QMetaObject>
#include <QMetaProperty>
#include <QDebug>
#include <QList>
#include <iostream>
#include "girldata.hpp"
#include "testclass.hpp"

Q_DECLARE_METATYPE(GirlData)
Q_DECLARE_METATYPE(TestClass)
//Q_DECLARE_METATYPE(QList<QString>)



int main(int argc, char *argv[])
{
	std::cout << std::endl;
	QCoreApplication a(argc, argv);

	qRegisterMetaType<GirlData>("GirlData");
	qRegisterMetaType<TestClass>("TestClass");

	TestClass * test = new TestClass();

	test->log();
	QList<QString> liste = test->property("names").value<QList<QString> >();
	liste.append(QString("hello world"));
	liste.append(QString("letti"));
	liste.append(QString("bouh"));
	test->setProperty("names", QVariant::fromValue(liste));
	test->log();

	QList<int> listeInt = test->property("ages").value<QList<int> >();
	listeInt.append(42);
	listeInt.append(51);
	listeInt.append(73);
	test->setProperty("ages", QVariant::fromValue(listeInt));
	test->log();

	QListBinder<QString> * qStringListBinder = new QListBinder<QString>("names", QStringTransformer::instance);
	QListBinder<int> * qIntListBinder = new QListBinder<int>("ages", IntTransformer::instance);

	XmlElement * list = new XmlElement("list", new ObjectBinder("", "TestClass"));
	XmlElement * value = new XmlElement("value", qStringListBinder);
	XmlElement * intval = new XmlElement("int", qIntListBinder);

	list->addChild(value);
	list->addChild(intval);

	try
	{
		XmlReader r(list);
		TestClass * g = (TestClass*)(r.read("d:/list.xml"));
		g->log();
		/*
		XmlWriter w(girl);
		w.write("d:/2.xml", g);
		*/
	}
	catch(QString & str)
	{
		qDebug() << "Exception : " << str;
	}

	for(int i = 0 ; i < 200000000 ; ++i);

	/*
	XmlElement * girl = new XmlElement("girl", new ObjectBinder("subchild", "GirlData"));
	XmlElement * subgirl = new XmlElement("girl", new ObjectBinder("subchild", "GirlData"));
	XmlElement * subsubgirl = new XmlElement("girl", new ObjectBinder("subchild", "GirlData"));
	XmlElement * name = new XmlElement("name", new ContentBinder("name", QStringTransformer::instance));
	XmlElement * age = new XmlElement("age", new ContentBinder("age", IntTransformer::instance));
	XmlElement * btrue = new XmlElement("true", new ContentBinder("btrue", BoolTransformer::instance));
	XmlElement * bfalse = new XmlElement("false", new ContentBinder("bfalse", BoolTransformer::instance));
	XmlElement * ffloat = new XmlElement("float", new ContentBinder("ffloat", FloatTransformer::instance));
	XmlElement * cchar = new XmlElement("char", new ContentBinder("cchar", CharTransformer::instance));

	XmlAttribute * bouhAttr = new XmlAttribute("bouh", "bouh", IntTransformer::instance);

	girl->addChild(name);
	girl->addChild(age);
	girl->addChild(btrue);
	girl->addChild(bfalse);
	girl->addChild(ffloat);
	girl->addChild(cchar);

	girl->addChild(subgirl);
	girl->addAttribute(bouhAttr);

	subgirl->addChild(name);
	subgirl->addChild(age);
	subgirl->addChild(btrue);
	subgirl->addChild(bfalse);
	subgirl->addChild(ffloat);
	subgirl->addChild(cchar);
	subgirl->addAttribute(bouhAttr);
	subgirl->addChild(subsubgirl);

	subsubgirl->addChild(name);
	subsubgirl->addChild(age);
	subsubgirl->addChild(btrue);
	subsubgirl->addChild(bfalse);
	subsubgirl->addChild(ffloat);
	subsubgirl->addChild(cchar);
	subsubgirl->addAttribute(bouhAttr);

	try
	{
		XmlReader r(girl);
		GirlData * g = (GirlData*)(r.read("d:/3.xml"));
		g->log();

		XmlWriter w(girl);
		w.write("d:/2.xml", g);
	}
	catch(QString & str)
	{
		qDebug() << "Exception : " << str;
	}
	*/
	return 0;
	//return a.exec();
}
