using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Tools
{
	/// <summary>
	/// This class is a pair of name and value to store an xml attribute.
	/// </summary>
	public class XmlAttributeData
	{
		/// <summary>
		/// The name of the attribute.
		/// </summary>
		protected string m_identifier = "";
		/// <summary>
		/// The value of the attribute.
		/// </summary>
		protected string m_value = "";

		/// <summary>
		/// Attribute's name.
		/// </summary>
		public string Identifier
		{
			get
			{
				return m_identifier;
			}
		}

		/// <summary>
		/// Attribute's value.
		/// </summary>
		public string Value
		{
			get
			{
				return m_value;
			}
		}

		/// <summary>
		/// Build a new attribute data.
		/// </summary>
		/// <param name="_identifier">Name of the attribute.</param>
		/// <param name="_value">Value of the attribute.</param>
		public XmlAttributeData(string _identifier, string _value)
		{
			this.m_identifier = _identifier;
			this.m_value = _value;
		}
	}
}
