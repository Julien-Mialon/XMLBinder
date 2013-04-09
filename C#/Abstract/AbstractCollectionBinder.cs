using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Abstract
{
	/// <summary>
	/// Abstract class for all collection binder item.
	/// </summary>
	public abstract class AbstractCollectionBinder : AbstractBinder
	{
		/// <summary>
		/// Create a new CollectionBinder with specified field name.
		/// </summary>
		/// <param name="_fieldName">The name of the collection field.</param>
		public AbstractCollectionBinder(string _fieldName)
			: base(_fieldName)
		{

		}

		/// <summary>
		/// Method to add an element to a collection.
		/// </summary>
		/// <param name="_source">Source object.</param>
		/// <param name="_fieldName">Name of the collection field in source object.</param>
		/// <param name="_add">The object to add.</param>
		public void addElement(object _source, string _fieldName, object _add)
		{
			IList collection = (IList)Tools.FieldAccess.getField(_source, _fieldName);
			collection.Add(_add);
		}


	}
}
