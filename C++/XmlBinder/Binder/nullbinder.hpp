#ifndef NULLBINDER_HPP
#define NULLBINDER_HPP

#include "XmlBinder_global.hpp"

#include "abstractbinder.hpp"

class XMLBINDERSHARED_EXPORT NullBinder : public AbstractBinder
{
	public:
		NullBinder();

		virtual QObject * read(QObject * _source, QString _content);
		virtual QString write(QObject * _source);
};

#endif // NULLBINDER_HPP
