#include "nullbinder.hpp"

NullBinder::NullBinder() : AbstractBinder("")
{

}

QObject * NullBinder::read(QObject * _source, QString _content)
{
	return _source;
}

QString NullBinder::write(QObject * _source)
{
	return "";
}
