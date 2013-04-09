#include "xmlattribute.hpp"

XmlAttribute::XmlAttribute()
{
	m_identifier = "";
	m_fieldName = "";
	m_transformer = nullptr;
}

XmlAttribute::XmlAttribute(const QString & _identifier, const QString & _fieldName, ITransformer * _transformer)
	: m_identifier(_identifier),
	  m_fieldName(_fieldName),
	  m_transformer(_transformer)
{

}

QString XmlAttribute::identifier()
{
	return m_identifier;
}

QString XmlAttribute::fieldName()
{
	return m_fieldName;
}

ITransformer * XmlAttribute::transformer()
{
	return m_transformer;
}

void XmlAttribute::read(QObject * _source, QString _value)
{
	QVariant v = transformer()->read(_value);
	if(!_source->setProperty(m_fieldName.toStdString().c_str(), v))
	{
		throw QString("Can not set value of field %1 on object %2").arg(m_fieldName, _source->objectName());
	}

}
