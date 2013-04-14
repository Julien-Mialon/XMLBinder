#ifndef XMLWRITER_HPP
#define XMLWRITER_HPP

#include <QtXml>
#include <QObject>
#include <QStack>

#include "XmlBinder_global.hpp"
#include "xmlelement.hpp"
#include "Tools/xmlattributedata.hpp"

class XMLBINDERSHARED_EXPORT XmlWriter
{
	public:
		XmlWriter(XmlElement * _rootElement);

		void write(QString _filename, QObject * _object);

	protected:
		XmlElement * getXmlElementByName(const QVector<XmlElement *> _elements, QString _tagName);

	protected:
		XmlElement * m_rootElement;
};

#endif // XMLWRITER_HPP
