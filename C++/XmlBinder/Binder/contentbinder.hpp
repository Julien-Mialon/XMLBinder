#ifndef CONTENTBINDER_HPP
#define CONTENTBINDER_HPP

#include "XmlBinder_global.hpp"

#include "abstractbinder.hpp"
#include "Interface/itransformer.hpp"

#include <QVariant>

class XMLBINDERSHARED_EXPORT ContentBinder : public AbstractBinder
{
	public:
		ContentBinder(const QString &_fieldName, ITransformer * _transformer);

		virtual QObject * read(QObject * _source, QString _content);
		virtual QString write(QObject * _source);

	protected:
		ITransformer * m_transformer;
};

#endif // CONTENTBINDER_HPP
