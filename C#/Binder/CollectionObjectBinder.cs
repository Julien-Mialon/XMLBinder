using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Abstract;
using XmlBinder.Interface;

namespace XmlBinder.Binder
{
	/// <summary>
	/// Binder to add object to IList member.
	/// </summary>
	public class CollectionObjectBinder : AbstractCollectionBinder
	{
		/// <summary>
		/// Type of object to create.
		/// </summary>
		protected Type m_objectType = null;

		/// <summary>
		/// Binder to bind content of xml tag if needed.
		/// </summary>
		protected BinderInterface m_contentBinder = null;

		/// <summary>
		/// Type of object to create.
		/// </summary>
		public Type ClassType
		{
			get
			{
				return m_objectType;
			}
		}

		/// <summary>
		/// Binder to bind xml tag content.
		/// </summary>
		public BinderInterface ContentBinder
		{
			get
			{
				return m_contentBinder;
			}
		}

		/// <summary>
		/// Create a new collection object binder.
		/// </summary>
		/// <param name="_fieldName">The name of the collection field.</param>
		/// <param name="_newType">The type of the object to create.</param>
		/// <param name="_contentBinder">The binder to use to xml content if needed.</param>
		public CollectionObjectBinder(string _fieldName, Type _newType, BinderInterface _contentBinder = null)
			: base(_fieldName)
		{
			m_objectType = _newType;
			m_contentBinder = _contentBinder;
		}

		public override object read(object _source, string _content)
		{
			object data = Activator.CreateInstance(ClassType);
			addElement(_source, FieldName, data);
			if (ContentBinder != null)
			{
				ContentBinder.read(data, _content);
			}
			return data;
		}

		public override string write(object _source)
		{
			if (ContentBinder != null)
			{
				//return ContentBinder.write(_source);
				return ContentBinder.write(ContentBinder.getAffectedField(_source));
			}
			return "";
		}
	}
}
