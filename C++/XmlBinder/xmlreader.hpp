#ifndef XMLREADER_HPP
#define XMLREADER_HPP

#include <QtXml>
#include "XmlBinder_global.hpp"

#include "xmlelement.hpp"

class XMLBINDERSHARED_EXPORT XmlReader
{
	public:
		XmlReader(XmlElement * _rootElement);

		QObject * read(QString _filename);

	protected:
		void recursiveCall(const QDomNode &_node, QString _tab = "");


	protected:
		XmlElement * m_rootElement;
};

#endif // XMLREADER_HPP
