#include "fieldaccess.hpp"

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
		_source->setProperty(_fieldName.toStdString().c_str(), _value);
	}
}
