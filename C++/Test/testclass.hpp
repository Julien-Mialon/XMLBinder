#ifndef TESTCLASS_HPP
#define TESTCLASS_HPP

#include <QObject>
#include <QDebug>

class TestClass : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QList<QString> names READ names WRITE setNames)
	Q_PROPERTY(QList<int> ages READ ages WRITE setAges)

	public:
		TestClass(QObject * parent = nullptr) : QObject(parent) {}
		TestClass(const TestClass & _other) : QObject() {m_names = _other.m_names;}

		/*
		QList<QVariant> names() {
			QList<QVariant> res;
			foreach(QString s, m_names)
			{
				res.append(QVariant(s));
			}

			return res;
		}

		void setNames(QList<QVariant> _names) {
			qDebug() << "call set QVariant";
			m_names.clear();
			foreach(QVariant v, _names)
			{
				m_names.append(v.value<QString>());
			}
		}
		*/
		void setNames(QList<QString> _names) {
			m_names = _names;
		}
		QList<QString> names() {
			return m_names;
		}

		void setAges(QList<int> _ages) {
			m_ages = _ages;
		}
		QList<int> ages() {
			return m_ages;
		}

	public slots:
		void log() {
			qDebug() << "m_names[" << m_names.length() << "](" << m_names << ")";
			qDebug() << "m_ages[" << m_ages.length() << "](" << m_ages << ")";
		}

	protected:
		QList<QString> m_names;
		QList<int> m_ages;
};

class ItemClass : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name READ name WRITE setName)
	Q_PROPERTY(int age READ age WRITE setAge)
	Q_PROPERTY(bool current READ current WRITE setCurrent)

	public:
		ItemClass(QObject * parent = nullptr) : QObject(parent), m_name("hello world"), m_age(73), m_current(false) {}
		ItemClass(const ItemClass & _other) : QObject() { m_name = _other.m_name; m_age = _other.m_age; m_current = _other.m_current; }

		ItemClass & operator=(const ItemClass & _other) {m_name = _other.m_name; m_age = _other.m_age; m_current = _other.m_current; return *this;}

		QString name() { return m_name; }
		void setName(const QString & _name) { m_name = _name; }

		int age() { return m_age; }
		void setAge(int _age) { m_age = _age; }

		bool current() { return m_current; }
		void setCurrent(bool _current) { m_current = _current; }
	public slots:
		void log() {
			qDebug() << "m_name(" << m_name << ") m_age(" << m_age << ") m_current(" << m_current << ")";
		}

	protected:
		QString m_name;
		int m_age;
		bool m_current;
};

class ItemsClass : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QList<ItemClass*> items READ items WRITE setItems)

	public:
		ItemsClass(QObject * parent = nullptr) : QObject(parent) {}
		ItemsClass(const ItemsClass & _other) : QObject() {m_items = _other.m_items;}

		void setItems(QList<ItemClass*> _items) {
			m_items = _items;
		}
		QList<ItemClass*> items() {
			return m_items;
		}
	public slots:
		void log() {
			qDebug() << "=== ItemsClass ===";
			foreach(ItemClass* item, m_items)
			{
				item->log();
			}
		}

	protected:
		QList<ItemClass*> m_items;
};



#endif // TESTCLASS_HPP
