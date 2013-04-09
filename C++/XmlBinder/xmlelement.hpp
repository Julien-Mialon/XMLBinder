#ifndef XMLELEMENT_HPP
#define XMLELEMENT_HPP

#include "XmlBinder_global.hpp"

#include <QObject>
#include <QString>
#include <QVector>

#include "xmlattribute.hpp"
#include "Interface/ibinder.hpp"
#include "Tools/xmlattributedata.hpp"

class XMLBINDERSHARED_EXPORT XmlElement
{
	public:
		XmlElement();
		XmlElement(QString _identifier, IBinder * _binder);

		QObject * read(QObject * _source, QString _xmlContent, const QVector<XmlAttributeData> & _attributes);
		//TODO : write mode.

		/// Getters / Setters
		QString identifier() const;
		IBinder * binder() const;
		QVector<XmlElement*> children() const;
		QVector<XmlAttribute*> attributes() const;

		void setIdentifier(QString _value);
		void setBinder(IBinder * _binder);
		void addChild(XmlElement * _element);
		void addAttribute(XmlAttribute * _attr);

	protected:
		XmlAttributeData extractAttributeData(const QVector<XmlAttributeData> & _attributes, QString _attributeName);

	protected:
		QString m_identifier;

		IBinder * m_binder;
		QVector<XmlElement*> m_children;
		QVector<XmlAttribute*> m_attributes;
};

#endif // XMLELEMENT_HPP
