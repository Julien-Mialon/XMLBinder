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

QString ContentBinder::write(QObject * _source)
{
	Q_UNUSED(_source);
	//TODO : write content binder part.
	return "";
}
