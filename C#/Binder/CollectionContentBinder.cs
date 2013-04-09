using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Abstract;
using XmlBinder.Interface;

namespace XmlBinder.Binder
{
	/// <summary>
	/// Bind xml content tag to collection member.
	/// </summary>
	public class CollectionContentBinder : AbstractCollectionBinder
	{
		/// <summary>
		/// Transformer to apply on data before saving.
		/// </summary>
		protected TransformerInterface m_transformer = null;

		/// <summary>
		/// Transformer to apply on data before writing & reading.
		/// </summary>
		public TransformerInterface Transformer
		{
			get
			{
				return m_transformer;
			}
		}
		
		/// <summary>
		/// Create rule to bind xml content tag to collection.
		/// </summary>
		/// <param name="_fieldName">The field name to collection member.</param>
		/// <param name="_transformer">The transformer to apply on data.</param>
		public CollectionContentBinder(string _fieldName, TransformerInterface _transformer)
			: base(_fieldName)
		{
			m_transformer = _transformer;
		}

		public override object read(object _source, string _content)
		{
			addElement(_source, FieldName, Transformer.read(_content));
			return _source;
		}

		public override string write(object _source)
		{
			return Transformer.write(_source);
		}
	}
}
