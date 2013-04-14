#include "floattransformer.hpp"

FloatTransformer * FloatTransformer::instance = new FloatTransformer();

FloatTransformer::FloatTransformer()
{
}


QVariant FloatTransformer::read(QString _value)
{
	bool ok = false;
	float number = _value.toFloat(&ok);
	if(!ok)
	{
		throw QString("Can not convert value %1 to float").arg(_value);
	}
	return number;
}

QString FloatTransformer::write(const QVariant & _value)
{
	if(_value.canConvert<float>())
	{
		return QString::number(_value.value<float>());
	}
	throw QString("Can not convert value to float");
}
