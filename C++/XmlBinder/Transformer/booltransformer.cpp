#include "booltransformer.hpp"

BoolTransformer * BoolTransformer::instance = new BoolTransformer();

BoolTransformer::BoolTransformer()
{
}


QVariant BoolTransformer::read(QString _value)
{
	bool ok = false;
	int number = _value.toInt(&ok);
	if(!ok)
	{
		throw QString("Can not convert value %1 to boolean").arg(_value);
	}
	return number == 1;
}

QString BoolTransformer::write(const QVariant & _value)
{
	if(_value.canConvert<bool>())
	{
		if(_value.value<bool>())
		{
			return QString("1");
		}
		else
		{
			return QString("0");
		}
	}
	throw QString("Can not convert value to boolean");
}
