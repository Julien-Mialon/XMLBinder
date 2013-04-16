#ifndef OBJECTTRANSFORMER_HPP
#define OBJECTTRANSFORMER_HPP

#include "XmlBinder_global.hpp"
#include "Interface/itransformer.hpp"
#include "Interface/ibinder.hpp"

#include <QString>

class XMLBINDERSHARED_EXPORT ObjectTransformer : public ITransformer
{
	public:
		ObjectTransformer(const QString & _className, IBinder * _contentBinder = nullptr);

		virtual QVariant read(QString _value);
		virtual QString write(const QVariant & _value);

	protected:
		QString m_className;
		IBinder * m_contentBinder;
};

#endif // OBJECTTRANSFORMER_HPP
