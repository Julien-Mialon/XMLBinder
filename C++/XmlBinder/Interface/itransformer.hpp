#ifndef ITRANSFORMER_HPP
#define ITRANSFORMER_HPP

#include "XmlBinder_global.hpp"

#include <QObject>
#include <QVariant>

class XMLBINDERSHARED_EXPORT ITransformer
{
	public:
		ITransformer();
		virtual ~ITransformer();

		virtual QVariant read(QString _value) = 0;
		virtual QString write(const QVariant & _value) = 0;
};

#endif // ITRANSFORMER_HPP
