#include "inttransformer.hpp"

IntTransformer * IntTransformer::instance = new IntTransformer();

IntTransformer::IntTransformer()
{
}


QVariant IntTransformer::read(QString _value)
{
	bool ok = false;
	int number = _value.toInt(&ok);
	if(!ok)
	{
		throw QString("Can not convert value %1 to int").arg(_value);
	}
	return number;
}

QString IntTransformer::write(const QVariant & _value)
{
	if(_value.canConvert<int>())
	{
		return QString::number(_value.value<int>());
	}
	throw QString("Can not convert value to int");
}
