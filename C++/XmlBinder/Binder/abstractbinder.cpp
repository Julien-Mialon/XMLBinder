#include "abstractbinder.hpp"

#include <QVariant>


AbstractBinder::AbstractBinder()
{
	m_fieldName = "";
}


AbstractBinder::AbstractBinder(const QString & _fieldName)
{
	m_fieldName = _fieldName;
}

QString AbstractBinder::fieldName()
{
	return m_fieldName;
}

void AbstractBinder::setFieldName(const QString & _fieldName)
{
	m_fieldName = _fieldName;
}

QObject * AbstractBinder::getAffectedField(QObject * source)
{
	if(source == nullptr)
	{
		return nullptr;
	}
	QVariant v = source->property(m_fieldName.toStdString().c_str());
	return v.value<QObject*>();
}
