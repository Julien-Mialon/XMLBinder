using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Abstract
{
	/// <summary>
	/// Abstract class for binder.
	/// </summary>
	public abstract class AbstractBinder : XmlBinder.Interface.BinderInterface
	{
		/// <summary>
		/// Name of field affected by Binder.
		/// </summary>
		protected string m_fieldName = "";

		/// <summary>
		/// Name of field affected by Binder.
		/// </summary>
		public string FieldName
		{
			get
			{
				return m_fieldName;
			}
		}

		/// <summary>
		/// Create AbstractBinder with field name.
		/// </summary>
		/// <param name="_fieldName">The name of the field affected by binder.</param>
		public AbstractBinder(string _fieldName)
		{
			m_fieldName = _fieldName;
		}

		/// <summary>
		/// Get value of field affected by the binder in _data object.
		/// </summary>
		/// <param name="_data">The source data object.</param>
		/// <returns>The value of the field.</returns>
		public object getAffectedField(object _data)
		{
			return Tools.FieldAccess.getField(_data, FieldName);
		}

		public abstract object read(object _source, string _content);
		public abstract string write(object _source);
	}
}
