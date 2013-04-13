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
	inputFile->close();
	delete inputFile;

	m_elements.clear();
	m_objects.clear();
	m_currentElement = new XmlElement();
	m_currentElement->addChild(m_rootElement);
	m_currentObject = nullptr;


	recursiveCall(document->documentElement());

	return m_lastObject;
}

void XmlReader::recursiveCall(const QDomNode & _node)
{
	if(_node.isElement())
	{
		QDomElement element = _node.toElement();
		XmlElement * xmlChildElement = getXmlElementByName(m_currentElement->children(), element.tagName());

		QVector<XmlAttributeData> attrs;
		if(_node.hasAttributes())
		{
			QDomNamedNodeMap attributes = _node.attributes();
			for(int i = 0 ; i < attributes.length() ; ++i)
			{
				QDomNode attrData = attributes.item(i);
				attrs.append(XmlAttributeData(attrData.nodeName(), attrData.nodeValue()));
			}
		}

		if(_node.hasChildNodes())
		{
			QDomNodeList children = _node.childNodes();
			if(children.size() == 1 && children.item(0).isText())
			{
				QString xmlContent = children.item(0).toText().data();
				xmlChildElement->read(m_currentObject, xmlContent, attrs);
			}
			else
			{
				m_objects.push(m_currentObject);
				m_elements.push(m_currentElement);
				m_currentObject = xmlChildElement->read(m_currentObject, "", attrs);
				m_currentElement = xmlChildElement;
				for(int i = 0 ; i < children.size() ; ++i)
				{
					recursiveCall(children.item(i));
				}
				m_lastObject = m_currentObject;
				m_currentObject = m_objects.pop();
				m_currentElement = m_elements.pop();
			}
		}
		else
		{
			xmlChildElement->read(m_currentObject, "", attrs);
		}
	}
}

XmlElement * XmlReader::getXmlElementByName(const QVector<XmlElement *> _elements, QString _tagName)
{
	foreach(XmlElement * element, _elements)
	{
		if(element->identifier() == _tagName)
		{
			return element;
		}
	}
	throw QString("No xml element for tag %1").arg(_tagName);
}
