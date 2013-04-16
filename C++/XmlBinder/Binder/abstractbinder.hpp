#ifndef ABSTRACTBINDER_HPP
#define ABSTRACTBINDER_HPP

#include "XmlBinder_global.hpp"

#include "Interface/ibinder.hpp"

#include <QString>
#include <QList>

class XMLBINDERSHARED_EXPORT AbstractBinder : public IBinder
{
	public:
		AbstractBinder();
		AbstractBinder(const QString & _fieldName);

		QString fieldName();
		void setFieldName(const QString & _fieldName);

		virtual QObject * getAffectedField(QObject * _source);

		virtual QObject * read(QObject * _source, QString _content) = 0;
		virtual QPair<QString, QObject *> write(QObject * _source) = 0;

		virtual bool isIterable();
		virtual QList<QPair<QString, QObject*> > writeIterableItem(QObject * _source);

	protected:
		QString m_fieldName;
};

#endif // ABSTRACTBINDER_HPP
