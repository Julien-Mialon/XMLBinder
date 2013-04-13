#ifndef FIELDACCESS_HPP
#define FIELDACCESS_HPP

#include <QObject>
#include <QString>
#include <QVariant>

class FieldAccess
{
	public:

		static QVariant value(QObject * _source, const QString & _fieldName);

		static void setValue(QObject * _source, const QString & _fieldName, const QVariant & _value);
};

#endif // FIELDACCESS_HPP
