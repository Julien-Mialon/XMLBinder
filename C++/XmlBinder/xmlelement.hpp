#ifndef XMLELEMENT_HPP
#define XMLELEMENT_HPP

#include "XmlBinder_global.hpp"

#include <QObject>
#include <iostream>

class XMLBINDERSHARED_EXPORT XmlElement : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int a READ bouh_a WRITE bouh_setA)

	public:
		XmlElement();

	public:
		void bouh_setA(int _a) { m_a = _a; std::cout << "Set A = " << m_a << std::endl; }
		int bouh_a() const { std::cout << "Get A = " << m_a << std::endl; return m_a; }


	protected:
		int m_a;
};

#endif // XMLELEMENT_HPP
