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


		void log() {
			qDebug() << "m_names[" << m_names.length() << "](" << m_names << ")";
			qDebug() << "m_ages[" << m_ages.length() << "](" << m_ages << ")";
		}

	protected:
		QList<QString> m_names;
		QList<int> m_ages;
};


#endif // TESTCLASS_HPP
