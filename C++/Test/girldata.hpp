#ifndef GIRLDATA_HPP
#define GIRLDATA_HPP

#include <QObject>

#include <QDebug>

class GirlData : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName)
	Q_PROPERTY(int age READ age WRITE setAge)
	Q_PROPERTY(bool btrue READ btrue WRITE setBtrue)
	Q_PROPERTY(bool bfalse READ bfalse WRITE setBfalse)
	Q_PROPERTY(float ffloat READ ffloat WRITE setFfloat)
	Q_PROPERTY(char cchar READ cchar WRITE setCchar)
	Q_PROPERTY(QObject* subchild READ subChild WRITE setSubChild)
	Q_PROPERTY(int bouh READ bouh WRITE setBouh)

	public:
		GirlData(QObject *parent = 0) : QObject(parent), m_name("hello world"), m_age(42) {m_subChild = nullptr; m_bouh = 73; }
		GirlData(const GirlData& _other) : QObject() {m_name = _other.m_name; m_age = _other.m_age; m_subChild = nullptr;  }

		void log()
		{
			QString n = m_name;
			int a = m_age;
			qDebug() << "GirlData : m_name(" << n << ") m_age(" << a << ") m_bouh(" << m_bouh << ") m_true(" << m_true << ") m_false(" << m_false << ") m_float(" << m_float << ") m_char(" << m_char << ")";

			if(subChild() != nullptr)
				subChild()->log();
		}

		QString name() { return m_name; }
		void setName(QString _name) { m_name = _name; }

		int age() { return m_age; }
		void setAge(int _age) { m_age = _age; }

		int bouh() { return m_bouh; }
		void setBouh(int _bouh) { m_bouh = _bouh; }

		bool btrue() { return m_true; }
		void setBtrue(bool _age) { m_true = _age; }

		bool bfalse() { return m_false; }
		void setBfalse(bool _age) { m_false = _age; }

		float ffloat() { return m_float; }
		void setFfloat(float _age) { m_float = _age; }

		char cchar() { return m_char; }
		void setCchar(char _age) { m_char = _age; }

		GirlData * subChild() { return m_subChild; }
		void setSubChild(QObject * _age) { m_subChild = qobject_cast<GirlData*>(_age); }

	protected:
		GirlData * m_subChild;

		QString m_name;
		int m_age;
		int m_bouh;

		bool m_true;
		bool m_false;
		float m_float;
		char m_char;
};
//Q_DECLARE_METATYPE(GirlData)

#endif // GIRLDATA_HPP
