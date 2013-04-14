#include "chartransformer.hpp"

CharTransformer * CharTransformer::instance = new CharTransformer();

CharTransformer::CharTransformer()
{
}


QVariant CharTransformer::read(QString _value)
{
	if(_value.size() <= 0)
	{
		throw QString("Can not convert value %1 to char").arg(_value);
	}
	return _value.toStdString().at(0);
}

QString CharTransformer::write(const QVariant & _value)
{
	if(_value.canConvert<char>())
	{
		return QString("%1").arg(_value.value<char>());
	}
	throw QString("Can not convert value to char");
}
