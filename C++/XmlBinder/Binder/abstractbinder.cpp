#include "abstractbinder.hpp"

#include <QVariant>
#include "Tools/fieldaccess.hpp"


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

QObject * AbstractBinder::getAffectedField(QObject * _source)
{
	if(_source == nullptr)
	{
		return nullptr;
	}
	QVariant v = FieldAccess::value(_source, m_fieldName);
	return v.value<QObject*>();
}

bool AbstractBinder::isIterable()
{
	return false;
}

QList<QPair<QString, QObject*> > AbstractBinder::writeIterableItem(QObject * _source)
{
	Q_UNUSED(_source)
	return QList<QPair<QString, QObject*> >();
}
