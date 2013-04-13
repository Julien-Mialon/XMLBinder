#ifndef XMLREADER_HPP
#define XMLREADER_HPP

#include "XmlBinder_global.hpp"

#include <QtXml>
#include <QObject>
#include <QStack>

#include "xmlelement.hpp"
#include "Tools/xmlattributedata.hpp"

class XMLBINDERSHARED_EXPORT XmlReader
{
	public:
		XmlReader(XmlElement * _rootElement);

		QObject * read(QString _filename);

	protected:
		void recursiveCall(const QDomNode &_node);

		XmlElement * getXmlElementByName(const QVector<XmlElement *> _elements, QString _tagName);

	protected:
		XmlElement * m_rootElement;

		QObject * m_currentObject;
		QObject * m_lastObject;
		XmlElement * m_currentElement;

		QStack<QObject *> m_objects;
		QStack<XmlElement *> m_elements;

};

#endif // XMLREADER_HPP
