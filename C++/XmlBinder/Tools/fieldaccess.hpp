#ifndef FIELDACCESS_HPP
#define FIELDACCESS_HPP

#include <QObject>
#include <QString>
#include <QVariant>

#include "XmlBinder_global.hpp"

class XMLBINDERSHARED_EXPORT FieldAccess
{
	public:

		static QVariant value(QObject * _source, const QString & _fieldName);

		static void setValue(QObject * _source, const QString & _fieldName, const QVariant & _value);
};

#endif // FIELDACCESS_HPP
