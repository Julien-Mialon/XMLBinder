using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Interface;
using XmlBinder.Tools;

namespace XmlBinder.Binder
{
	/// <summary>
	/// Binder to bind the content of Xml tag.
	/// </summary>
	public class ContentBinder : XmlBinder.Abstract.AbstractBinder
	{
		/// <summary>
		/// Transformer to apply before saving data from xml.
		/// </summary>
		protected TransformerInterface m_transformer;

		/// <summary>
		/// Transformer to apply on data.
		/// </summary>
		public TransformerInterface Transformer
		{
			get
			{
				return m_transformer;
			}
		}

		/// <summary>
		/// Create a content binder to bind data turn with transformer into the field name.
		/// </summary>
		/// <param name="_fieldName">The name of the field to save data.</param>
		/// <param name="_transformer">The transformer to use to turn data into other format.</param>
		public ContentBinder(string _fieldName, TransformerInterface _transformer) : base(_fieldName)
		{
			m_transformer = _transformer;
		}

		public override object read(object _source, string _content)
		{
			object data = Transformer.read(_content);
			FieldAccess.setField(_source, FieldName, data);
			return data;
		}

		public override string write(object _source)
		{
			//object data = FieldAccess.getField(_source, FieldName);
			//return Transformer.write(data);
			return Transformer.write(_source);
		}
	}
}
