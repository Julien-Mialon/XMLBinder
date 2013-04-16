#ifndef QLISTBINDER_TPP
#define QLISTBINDER_TPP

#ifdef QLISTBINDER_TEMPLATE_IMPORT

#include "Tools/fieldaccess.hpp"

template<typename T>
QListBinder<T>::QListBinder(const QString & _fieldName, ITransformer * _internalTransformer)
	: AbstractBinder(_fieldName)
{
	m_internalTransformer = _internalTransformer;
}

template<typename T>
QObject * QListBinder<T>::read(QObject * _source, QString _content)
{
	QVariant value = m_internalTransformer->read(_content);
	QObject * res = _source;
	if(value.canConvert(QMetaType::QObjectStar))
	{
		res = value.value<QObject*>();
	}

	//add to list
	QVariant listValue = FieldAccess::value(_source, this->fieldName());
	QList<T> list = listValue.value< QList<T> >();
	list.append(value.value<T>());
	FieldAccess::setValue(_source, this->fieldName(), QVariant::fromValue(list));

	return res;
}

template<typename T>
QPair<QString, QObject *> QListBinder<T>::write(QObject * _source)
{
	Q_UNUSED(_source)
	//TODO
	return QPair<QString, QObject*>("", nullptr);
}

#endif

#endif
