#ifndef BOOLTRANSFORMER_HPP
#define BOOLTRANSFORMER_HPP

#include "XmlBinder_global.hpp"
#include "Interface/itransformer.hpp"

class XMLBINDERSHARED_EXPORT BoolTransformer : public ITransformer
{
	public:
		static BoolTransformer * instance;

	public:
		BoolTransformer();

		virtual QVariant read(QString _value);
		virtual QString write(const QVariant & _value);
};

#endif // BOOLTRANSFORMER_HPP
