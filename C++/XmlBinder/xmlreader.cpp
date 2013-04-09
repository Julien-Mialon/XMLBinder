#include "xmlreader.hpp"

#include <stdexcept>
#include <iostream>


XmlReader::XmlReader(XmlElement * _rootElement)
{
	std::cout << std::endl;
	this->m_rootElement = _rootElement;
}

QObject * XmlReader::read(QString _filename)
{
	QFile * inputFile = new QFile(_filename);

	if(!inputFile->open(QIODevice::ReadOnly))
	{
		delete inputFile;
		throw new std::runtime_error("XmlReader : Can not open file");
	}

	QDomDocument * document = new QDomDocument("XmlReaderDocument");
	document->setContent(inputFile);

	QDomElement rootElement = document->documentElement();
	QDomNode rootNode = rootElement.firstChild();

	recursiveCall(document->documentElement());
	/*
	qDebug() << "";
	qDebug() << "<" << rootElement.tagName() << ">";
	while(!rootNode.isNull())
	{
		QDomElement currentElement = rootNode.toElement();
		if(!currentElement.isNull())
		{
			if(currentElement.hasChildNodes())
			{
				qDebug() << "<" << currentElement.tagName() << ">";

				qDebug() << "</" << currentElement.tagName() << ">";
			}
			else
			{
				qDebug() << "<" << currentElement.tagName() << ">" << currentElement.toText().data() << "</" << currentElement.tagName() << ">";
			}
		}
		rootNode = rootNode.nextSibling();
	}
	qDebug() << "</" << rootElement.tagName() << ">";
	*/
	inputFile->close();
	return NULL;
}

void XmlReader::recursiveCall(const QDomNode & _node, QString _tab)
{
	if(_node.isElement())
	{
		QDomElement element = _node.toElement();

		QString attr = "";
		if(_node.hasAttributes())
		{
			QDomNamedNodeMap attributes = _node.attributes();
			for(int i = 0 ; i < attributes.length() ; ++i)
			{
				QDomNode a = attributes.item(i);

				attr += a.nodeName() + "='" + a.nodeValue() + "'";
			}
		}

		std::cout << _tab.toStdString() << "<" << element.tagName().toStdString() << " " << attr.toStdString() << ">" << std::endl;

		if(_node.hasChildNodes())
		{
			QDomNode node = _node.firstChild();
			while(!node.isNull())
			{
				recursiveCall(node, _tab + "\t");
				node = node.nextSibling();
			}
		}

		std::cout << _tab.toStdString() << "</" << element.tagName().toStdString() << ">" << std::endl;
	}
	else if(_node.isText())
	{
		std::cout << _tab.toStdString() << _node.toText().data().toStdString() << std::endl;
	}
}
