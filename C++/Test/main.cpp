#include <QCoreApplication>

#include <XmlBinder_global.hpp>
#include <xmlelement.hpp>
#include <xmlreader.hpp>

#include <QMetaObject>
#include <QMetaProperty>

#include <iostream>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	XmlElement * b = new XmlElement();
/*
	const QMetaObject * obj = b->metaObject();
	int indA = obj->indexOfProperty("a");
	QMetaProperty prop = obj->property(indA);
*/

	XmlReader r(NULL);
	r.read("d:/3.xml");
/*
	std::cout << b->property("a").value<int>() << std::endl;

	b->setProperty("a", 73);

	std::cout << b->property("a").value<int>() << std::endl;
*/
	return a.exec();
}
