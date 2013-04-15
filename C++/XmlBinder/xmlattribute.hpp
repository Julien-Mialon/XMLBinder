#ifndef XMLATTRIBUTE_HPP
#define XMLATTRIBUTE_HPP

#include "XmlBinder_global.hpp"

#include <QString>
#include <QObject>
#include <QtXml>

#include "Interface/itransformer.hpp"
#include "Tools/fieldaccess.hpp"

class XMLBINDERSHARED_EXPORT XmlAttribute
{
	public:
		XmlAttribute();
		XmlAttribute(const QString & _identifier, const QString & _fieldName, ITransformer * _transformer);

		QString identifier();
		QString fieldName();
		ITransformer * transformer();

		void read(QObject * _source, QString _value);
		void write(QObject * _source, QXmlStreamWriter * _writer);

	protected:
		QString m_identifier;
		QString m_fieldName;

		ITransformer * m_transformer;
};

#endif // XMLATTRIBUTE_HPP
