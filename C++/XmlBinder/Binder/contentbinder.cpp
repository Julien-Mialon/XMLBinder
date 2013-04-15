#include "contentbinder.hpp"
#include "Tools/fieldaccess.hpp"

ContentBinder::ContentBinder(const QString & _fieldName, ITransformer * _transformer)
	: AbstractBinder(_fieldName)
{
	m_transformer = _transformer;
}

QObject * ContentBinder::read(QObject * _source, QString _content)
{
	QVariant value = m_transformer->read(_content);
	FieldAccess::setValue(_source, this->fieldName(), value);
	return _source;
}

QPair<QString, QObject *> ContentBinder::write(QObject * _source)
{
	QVariant v = FieldAccess::value(_source, this->fieldName());
	return QPair<QString, QObject*>(m_transformer->write(v), _source);
}
