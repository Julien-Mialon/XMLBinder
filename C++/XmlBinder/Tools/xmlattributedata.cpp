#include "xmlattributedata.hpp"

XmlAttributeData::XmlAttributeData()
{
	m_name = "";
	m_value = "";
}

XmlAttributeData::XmlAttributeData(const QString & _name, const QString & _value)
{
	m_name = _name;
	m_value = _value;
}

QString XmlAttributeData::name() const
{
	return m_name;
}

QString XmlAttributeData::value() const
{
	return m_value;
}

void XmlAttributeData::setName(const QString & _name)
{
	m_name = _name;
}

void XmlAttributeData::setValue(const QString & _value)
{
	m_value = _value;
}
