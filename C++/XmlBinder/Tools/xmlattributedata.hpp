#ifndef XMLATTRIBUTEDATA_HPP
#define XMLATTRIBUTEDATA_HPP

#include <QString>

class XmlAttributeData
{
	public:
		XmlAttributeData();
		XmlAttributeData(const QString & _name, const QString & _value);

		QString name() const;
		QString value() const;

		void setName(const QString & _name);
		void setValue(const QString & _value);

	protected:
		QString m_name;
		QString m_value;
};

#endif // XMLATTRIBUTEDATA_HPP
