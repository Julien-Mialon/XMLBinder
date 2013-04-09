using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using XmlBinder.Interface;
using XmlBinder.Tools;

namespace XmlBinder
{
	/// <summary>
	/// This class will contains rules to bind xml attribute to data object.
	/// </summary>
	public class XmlAttribute
	{
		/// <summary>
		/// The attribute name.
		/// </summary>
		protected string m_identifier = "";

		/// <summary>
		/// The name of the field object to bind to.
		/// </summary>
		protected string m_fieldName = "";
		
		/// <summary>
		/// The Transformer to apply before saving data.
		/// </summary>
		protected TransformerInterface m_transformer = null;

		#region public field
		/// <summary>
		/// The Xml attribute name.
		/// </summary>
		public string Identifier
		{
			get
			{
				return m_identifier;
			}
		}

		/// <summary>
		/// The name of field in the object to bind to data.
		/// </summary>
		public string FieldName
		{
			get
			{
				return m_fieldName;
			}
		}

		/// <summary>
		/// The transformer to apply before saving data.
		/// </summary>
		public TransformerInterface Transformer
		{
			get
			{
				return m_transformer;
			}
		}
		#endregion

		/// <summary>
		/// Construct a rule to bind xml attribute.
		/// </summary>
		/// <param name="_identifier">The xml attribute name.</param>
		/// <param name="_fieldName">The name of field in object.</param>
		/// <param name="_transformer">The transformer to apply.</param>
		public XmlAttribute(string _identifier, string _fieldName, TransformerInterface _transformer)
		{
			this.m_identifier = _identifier;
			this.m_fieldName = _fieldName;
			this.m_transformer = _transformer;
		}

		/// <summary>
		/// Method to execute read action on attribute.
		/// </summary>
		/// <param name="_data">The object where to save data.</param>
		/// <param name="_value">The value of attribute in xml file.</param>
		public void read(object _data, string _value)
		{
			FieldAccess.setField(_data, this.FieldName, this.Transformer.read(_value));
		}

		/// <summary>
		/// Method to write content to xml attribute.
		/// </summary>
		/// <param name="_writer">The XmlWriter object to write file.</param>
		/// <param name="_data">The object which contains data to save.</param>
		public void write(System.Xml.XmlWriter _writer, object _data)
		{
			_writer.WriteStartAttribute(Identifier);
			_writer.WriteValue(Transformer.write(FieldAccess.getField(_data, FieldName)));
			_writer.WriteEndAttribute();
		}
	}
}
