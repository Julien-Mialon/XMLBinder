using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Tools
{
	/// <summary>
	/// Class to enable easy access to field of object using reflexivity.
	/// </summary>
	class FieldAccess
	{
		/// <summary>
		/// Method to get the value of a field in an object.
		/// </summary>
		/// <param name="_data">The data object.</param>
		/// <param name="_fieldName">The name of the field.</param>
		/// <returns>The value of the field or null if _data or _fieldName is null or empty.</returns>
		/// <exception cref="XmlBinder.Exception.FieldAccessException">If the field does not exists.</exception>
		public static object getField(object _data, string _fieldName)
		{
            if (_data == null || _fieldName == null || _fieldName == "")
            {
                return _data;
            }
			Type t = _data.GetType();
			try
			{
				System.Reflection.FieldInfo field = t.GetField(_fieldName, System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Public);

				return field.GetValue(_data);
			}
			catch (System.Exception)
			{
				throw new XmlBinder.Exception.FieldAccessException("FieldAccess", "getField", "Unable to get the field " + _fieldName + " in the object of type " + _data.GetType().ToString());
			}
		}

		/// <summary>
		/// Method to change the value of a field.
		/// </summary>
		/// <param name="_data">The object where to change the value of field.</param>
		/// <param name="_fieldName">The name of the field to change.</param>
		/// <param name="_value">The new value of the field.</param>
		public static void setField(object _data, string _fieldName, object _value)
		{
            if (_data == null || _fieldName == null || _fieldName == "")
            {
                return;
            }
			Type t = _data.GetType();
			try
			{
				System.Reflection.FieldInfo field = t.GetField(_fieldName, System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Public);

				field.SetValue(_data, _value);
			}
			catch (System.Exception)
			{
				throw new XmlBinder.Exception.FieldAccessException("FieldAccess", "setField", "Unable to set the field " + _fieldName + " in the object of type " + _data.GetType().ToString() + " with a value of type " + _value.GetType().ToString());
			}
		}
	}
}
