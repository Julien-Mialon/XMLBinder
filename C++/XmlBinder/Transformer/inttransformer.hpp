#ifndef INTTRANSFORMER_HPP
#define INTTRANSFORMER_HPP

#include "XmlBinder_global.hpp"
#include "Interface/itransformer.hpp"

class XMLBINDERSHARED_EXPORT IntTransformer : public ITransformer
{
	public:
		static IntTransformer * instance;

	public:
		IntTransformer();

		virtual QVariant read(QString _value);
		virtual QString write(const QVariant & _value);
};

#endif // INTTRANSFORMER_HPP
