#ifndef IBINDER_HPP
#define IBINDER_HPP

#include "XmlBinder_global.hpp"

#include <QObject>
#include <QString>
#include <QPair>

class XMLBINDERSHARED_EXPORT IBinder
{
	public:
		IBinder();
		virtual ~IBinder();

		/**
		 * @brief read Method to convert string representation to object one.
		 * @param _source : the source object where to store data.
		 * @param _content : the string representation of the object.
		 * @return the new created object or if not applicable, the _source parameter.
		 */
		virtual QObject * read(QObject * _source, QString _content) = 0;

		/**
		 * @brief write Method to convert object to string representation.
		 * @param _source : the object to convert to string.
		 * @return <string representation of the parameter, QObject* next child data to use>
		 */
		virtual QPair<QString, QObject *> write(QObject * _source) = 0;

		/**
		 * @brief getAffectedField Method to get the value of the field affected by this binder.
		 * @param source : the source object where to extract value.
		 * @return the value of the field affected by this binder.
		 */
		virtual QObject * getAffectedField(QObject * source) = 0;

		/**
		 * @brief isIterable Method to know if a binder is used for a collection and needs to be iterate while writing.
		 * @return true if collection, false otherwise.
		 */
		virtual bool isIterable() = 0;

		/**
		 * @brief writeIterableItem Method to convert collections objects to string representation.
		 * @param _source : the object where to find the collection to convert.
		 * @return list of all converted object which was in the collection.
		 */
		virtual QList<QPair<QString, QObject*> > writeIterableItem(QObject * _source) = 0;
};

#endif // IBINDER_HPP
