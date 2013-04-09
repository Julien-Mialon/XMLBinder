#include "qstringtransformer.hpp"

#include <QString>

QStringTransformer * QStringTransformer::instance = new QStringTransformer();

QStringTransformer::QStringTransformer()
{

}

QVariant QStringTransformer::read(QString _value)
{
	return QVariant(_value);
}

QString QStringTransformer::write(const QVariant & _value)
{
	if(_value.canConvert<QString>())
	{
		return _value.value<QString>();
	}
	throw QString("Can not convert value to QString");
}
