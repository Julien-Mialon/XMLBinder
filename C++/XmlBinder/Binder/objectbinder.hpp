#ifndef OBJECTBINDER_HPP
#define OBJECTBINDER_HPP

#include "XmlBinder_global.hpp"

#include "abstractbinder.hpp"

class XMLBINDERSHARED_EXPORT ObjectBinder : public AbstractBinder
{
	public:
		ObjectBinder(const QString & _fieldName, const QString & _objectClassName);

		virtual QObject * read(QObject * _source, QString _content);
		virtual QString write(QObject * _source);

	protected:
		QString m_objectClassName;
};

#endif // OBJECTBINDER_HPP
