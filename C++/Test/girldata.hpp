#ifndef GIRLDATA_HPP
#define GIRLDATA_HPP

#include <QObject>

#include <QDebug>

class GirlData : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName)
	Q_PROPERTY(QString age READ age WRITE setAge)

	public:
		GirlData(QObject *parent = 0) : QObject(parent), m_name("hello world"), m_age("hello world") {}
		GirlData(const GirlData& _other) : QObject() {m_name = _other.m_name; m_age = _other.m_age; }

		void log()
		{
			QString n = m_name;
			QString a = m_age;
			qDebug() << "GirlData : m_name(" << n << ") m_age(" << a << ")";
		}

		QString name() { return m_name; }
		void setName(QString _name) { m_name = _name; }

		QString age() { return m_age; }
		void setAge(QString _age) { m_age = _age; }

	protected:
		QString m_name;
		QString m_age;
};
//Q_DECLARE_METATYPE(GirlData)

#endif // GIRLDATA_HPP
