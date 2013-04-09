using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Interface
{
	public interface TransformerInterface
	{
		/// <summary>
		/// Function to convert a string stored in file to an object.
		/// </summary>
		/// <param name="_value">The string read in the file.</param>
		/// <returns>The object converted from the string.</returns>
		object read(string _value);

		/// <summary>
		/// Function to convert an object to string to store it to a file.
		/// </summary>
		/// <param name="_value">The object to convert.</param>
		/// <returns>The string which is the converted representation of the object.</returns>
		string write(object _value);
	}
}
