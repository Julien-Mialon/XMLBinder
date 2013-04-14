#include "fieldaccess.hpp"
#include <QDebug>
#include <QMetaProperty>
QVariant FieldAccess::value(QObject * _source, const QString & _fieldName)
{
	if(_source != nullptr && !_fieldName.isEmpty())
	{
		return _source->property(_fieldName.toStdString().c_str());
	}
	return QVariant();
}

void FieldAccess::setValue(QObject * _source, const QString & _fieldName, const QVariant & _value)
{
	if(_source != nullptr && !_fieldName.isEmpty())
	{
		bool res = _source->setProperty(_fieldName.toStdString().c_str(), _value);
		if(!res)
		{
			throw QString("Can not set value of field %1 in object of type %2").arg(_fieldName, _source->metaObject()->className());
		}
	}
}
