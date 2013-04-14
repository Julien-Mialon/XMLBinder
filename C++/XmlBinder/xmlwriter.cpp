#include "xmlwriter.hpp"

#include <QXmlStreamWriter>

XmlWriter::XmlWriter(XmlElement * _rootElement)
{
	m_rootElement = _rootElement;
}

void XmlWriter::write(QString _filename, QObject * _object)
{
	QFile * outputFile = new QFile(_filename);
	if(outputFile->open(QIODevice::WriteOnly))
	{
		QXmlStreamWriter * writer = new QXmlStreamWriter();
		writer->setDevice(outputFile);
		writer->setAutoFormatting(true);
		writer->setAutoFormattingIndent(-1);

		writer->writeStartDocument();

		m_rootElement->write(_object, writer);

		writer->writeEndDocument();
		delete writer;
	}
	delete outputFile;
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
