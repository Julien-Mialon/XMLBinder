#include "objecttransformer.hpp"

ObjectTransformer::ObjectTransformer(const QString & _className, IBinder * _contentBinder)
{
	m_className = _className;
	m_contentBinder = _contentBinder;
}

QVariant ObjectTransformer::read(QString _value)
{
	int type = QMetaType::type(m_className.toStdString().c_str());
	QObject * object = (QObject*)QMetaType::create(type);

	if(m_contentBinder != nullptr)
	{
		m_contentBinder->read(object, _value);
	}

	return QVariant::fromValue(object);
}

QString ObjectTransformer::write(const QVariant & _value)
{
	QString content = "";

	if(_value.canConvert(QMetaType::QObjectStar))
	{
		if(m_contentBinder != nullptr)
		{
			content = m_contentBinder->write(_value.value<QObject*>()).first;
		}
		return content;
	}
	else
	{
		throw QString("Value of type %1 is not a QObject*").arg(_value.typeName());
	}
}
