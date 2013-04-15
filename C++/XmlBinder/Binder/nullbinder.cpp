#include "nullbinder.hpp"

NullBinder::NullBinder() : AbstractBinder("")
{

}

QObject * NullBinder::read(QObject * _source, QString _content)
{
	Q_UNUSED(_content)
	return _source;
}

QPair<QString, QObject *> NullBinder::write(QObject * _source)
{
	return QPair<QString, QObject*>("", _source);
}
