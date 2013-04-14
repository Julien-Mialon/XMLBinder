#ifndef FLOATTRANSFORMER_HPP
#define FLOATTRANSFORMER_HPP

#include "XmlBinder_global.hpp"
#include "Interface/itransformer.hpp"

class XMLBINDERSHARED_EXPORT FloatTransformer : public ITransformer
{
	public:
		static FloatTransformer * instance;

	public:
		FloatTransformer();

		virtual QVariant read(QString _value);
		virtual QString write(const QVariant & _value);
};

#endif // FLOATTRANSFORMER_HPP
