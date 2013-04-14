#ifndef CHARTRANSFORMER_HPP
#define CHARTRANSFORMER_HPP

#include "XmlBinder_global.hpp"
#include "Interface/itransformer.hpp"

class XMLBINDERSHARED_EXPORT CharTransformer : public ITransformer
{
	public:
		static CharTransformer * instance;

	public:
		CharTransformer();

		virtual QVariant read(QString _value);
		virtual QString write(const QVariant & _value);
};

#endif // CHARTRANSFORMER_HPP
