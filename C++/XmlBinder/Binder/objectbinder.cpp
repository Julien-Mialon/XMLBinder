#include "objectbinder.hpp"

#include "Tools/fieldaccess.hpp"

ObjectBinder::ObjectBinder(const QString & _fieldName, const QString & _objectClassName, IBinder * _contentBinder)
	: AbstractBinder(_fieldName), m_objectClassName(_objectClassName), m_contentBinder(_contentBinder)
{

}

QObject * ObjectBinder::read(QObject * _source, QString _content)
{
	int type = QMetaType::type(m_objectClassName.toStdString().c_str());
	QObject * object = (QObject*)QMetaType::create(type);

	FieldAccess::setValue(_source, this->fieldName(), QVariant::fromValue(object));

	if(m_contentBinder != nullptr)
	{
		m_contentBinder->read(object, _content);
	}

	return object;
}

QPair<QString, QObject *> ObjectBinder::write(QObject * _source)
{
	QString content = "";
	QObject * affectedField = this->getAffectedField(_source);
	if(m_contentBinder != nullptr)
	{
		content = m_contentBinder->write(affectedField).first;
	}
	return QPair<QString, QObject*>(content, affectedField);
}
