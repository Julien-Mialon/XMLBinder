#ifndef QSTRINGTRANSFORMER_HPP
#define QSTRINGTRANSFORMER_HPP

#include "XmlBinder_global.hpp"
#include "Interface/itransformer.hpp"

class XMLBINDERSHARED_EXPORT QStringTransformer : public ITransformer
{
	public:
		static QStringTransformer * instance;

	public:
		QStringTransformer();

		virtual QVariant read(QString _value);
		virtual QString write(const QVariant & _value);
};

#endif // QSTRINGTRANSFORMER_HPP
