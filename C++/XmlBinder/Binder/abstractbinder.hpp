#ifndef ABSTRACTBINDER_HPP
#define ABSTRACTBINDER_HPP

#include "XmlBinder_global.hpp"

#include "Interface/ibinder.hpp"

#include <QString>

class XMLBINDERSHARED_EXPORT AbstractBinder : public IBinder
{
	public:
		AbstractBinder();
		AbstractBinder(const QString & _fieldName);

		QString fieldName();
		void setFieldName(const QString & _fieldName);

		virtual QObject * getAffectedField(QObject * source);

		virtual QObject * read(QObject * _source, QString _content) = 0;
		virtual QString write(QObject * _source) = 0;

	protected:
		QString m_fieldName;
};

#endif // ABSTRACTBINDER_HPP
