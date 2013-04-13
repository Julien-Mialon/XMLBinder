#include "objectbinder.hpp"

ObjectBinder(const QString & _fieldName, const QString & _objectClassName)
	: AbstractBinder(_fieldName), m_objectClassName(_objectClassName)
{
	m_objectClassName = _objectClassName;
	QMetaType type = QMetaType::type(m_objectClassName.toStdString().c_str());
}

QObject * read(QObject * _source, QString _content)
{

}

QString write(QObject * _source)
{

}
