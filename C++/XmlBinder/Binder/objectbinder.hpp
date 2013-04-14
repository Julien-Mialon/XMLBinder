#ifndef OBJECTBINDER_HPP
#define OBJECTBINDER_HPP

#include "XmlBinder_global.hpp"

#include "abstractbinder.hpp"
#include "Interface/ibinder.hpp"

#include <QMetaObject>
#include <QVariant>

class XMLBINDERSHARED_EXPORT ObjectBinder : public AbstractBinder
{
	public:
		ObjectBinder(const QString & _fieldName, const QString & _objectClassName, IBinder * _contentBinder = nullptr);

		virtual QObject * read(QObject * _source, QString _content);
		virtual QString write(QObject * _source);

	protected:
		QString m_objectClassName;
		IBinder * m_contentBinder;
};

#endif // OBJECTBINDER_HPP
