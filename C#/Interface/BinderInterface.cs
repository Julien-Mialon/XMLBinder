using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Interface
{
	public interface BinderInterface
	{
		/// <summary>
		/// Function to bind xml content to object representation.
		/// </summary>
		/// <param name="_source">The ancestor object to store the new one.</param>
		/// <param name="_content">The xml content of the tag.</param>
		/// <returns>The new created object.</returns>
        object read(object _source, string _content);

		/// <summary>
		/// Method to convert object representation to string.
		/// </summary>
		/// <param name="_source">The ancestor object.</param>
		/// <returns>A string representation of object data.</returns>
		string write(object _source);

		/// <summary>
		/// Method to get the value of the field affected by the Binder.
		/// </summary>
		/// <param name="_source">The ancestor object.</param>
		/// <returns>The value of the affected field.</returns>
		object getAffectedField(object _source);
	}
}
