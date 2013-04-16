#ifndef QLISTBINDER_HPP
#define QLISTBINDER_HPP

#include "XmlBinder_global.hpp"
#include "Interface/ibinder.hpp"
#include "Interface/itransformer.hpp"
#include "abstractbinder.hpp"
#include "Tools/fieldaccess.hpp"


#include <QList>

template<typename T>
class XMLBINDERSHARED_EXPORT QListBinder : public AbstractBinder
{
	public:
		QListBinder(const QString & _fieldName, ITransformer * _internalTransformer);

		virtual QObject * read(QObject * _source, QString _content);
		virtual QPair<QString, QObject *> write(QObject * _source);

	protected:
		ITransformer * m_internalTransformer;
};

#define QLISTBINDER_TEMPLATE_IMPORT
#include "qlistbinder.tpp"
#undef QLISTBINDER_TEMPLATE_IMPORT

#endif // QLISTBINDER_HPP
