#include "xmlelement.hpp"

bool XmlElement::s_firstStep = false;

XmlElement::XmlElement()
{

}

XmlElement::XmlElement(QString _identifier, IBinder * _binder)
	: m_identifier(_identifier),
	  m_binder(_binder)
{

}

QObject * XmlElement::read(QObject * _source, QString _xmlContent, const QVector<XmlAttributeData> & _attributes)
{
	QObject * newObject = binder()->read(_source, _xmlContent);

	foreach(XmlAttribute * attr, m_attributes)
	{
		XmlAttributeData attrData = extractAttributeData(_attributes, attr->identifier());
		attr->read(newObject, attrData.value());
	}

	return newObject;
}

void XmlElement::write(QObject * _data, QXmlStreamWriter * _writer)
{
	_writer->writeStartElement(this->m_identifier);

	bool first = XmlElement::s_firstStep;
	XmlElement::s_firstStep = false;

	QPair<QString, QObject *> res = m_binder->write(_data);

	foreach(XmlAttribute* attr, m_attributes)
	{
		attr->write(first ? _data : res.second, _writer);
	}

	_writer->writeCharacters(res.first);

	foreach(XmlElement* child, m_children)
	{
		child->write(first ? _data : res.second, _writer);
	}

	_writer->writeEndElement();
}

/// Getters / Setters

QString XmlElement::identifier() const
{
	return m_identifier;
}

IBinder * XmlElement::binder() const
{
	return m_binder;
}

QVector<XmlElement*> XmlElement::children() const
{
	return m_children;
}

QVector<XmlAttribute*> XmlElement::attributes() const
{
	return m_attributes;
}

void XmlElement::setIdentifier(QString _value)
{
	m_identifier = _value;
}

void XmlElement::setBinder(IBinder * _binder)
{
	m_binder = _binder;
}

void XmlElement::addChild(XmlElement * _element)
{
	m_children.append(_element);
}

void XmlElement::addAttribute(XmlAttribute * _attr)
{
	m_attributes.append(_attr);
}


/// Protected methods

XmlAttributeData XmlElement::extractAttributeData(const QVector<XmlAttributeData> & _attributes, QString _attributeName)
{
	foreach(XmlAttributeData data, _attributes)
	{
		if(data.name() == _attributeName)
		{
			return data;
		}
	}
	throw QString("Can not find attribute with name %1").arg(_attributeName);
}
