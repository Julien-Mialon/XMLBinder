using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Interface;
using XmlBinder.Tools;

namespace XmlBinder.Binder
{
	/// <summary>
	/// Binder used to create an object of the specified type when the xml tag is encoutered.
	/// </summary>
	public class ObjectBinder : XmlBinder.Abstract.AbstractBinder
	{
		/// <summary>
		/// Type of the object to create.
		/// </summary>
		protected Type m_classType;

		/// <summary>
		/// Binder to bind content of the xml tag.
		/// </summary>
		protected BinderInterface m_contentBinder;

		/// <summary>
		/// Type to create object.
		/// </summary>
		public Type ClassType
		{
			get
			{
				return m_classType;
			}
		}

		/// <summary>
		/// Binder to bind content of xml tag if needed.
		/// </summary>
		public BinderInterface ContentBinder
		{
			get
			{
				return m_contentBinder;
			}
		}

		/// <summary>
		/// Build a binder with specified class type and content binder.
		/// </summary>
		/// <param name="_fieldName">The field to bind the new object to.</param>
		/// <param name="_classType">The type of the new object.</param>
		/// <param name="_contentBinder">A Binder to bind the content of xml tag if needed.</param>
		public ObjectBinder(string _fieldName, Type _classType, BinderInterface _contentBinder = null) : base(_fieldName)
		{
			m_classType = _classType;
			m_contentBinder = _contentBinder;
		}

		/// <see cref="BinderInterface.read()"/>
		public override object read(object _source, string _content)
		{
			object data = Activator.CreateInstance(ClassType);
			FieldAccess.setField(_source, FieldName, data);
			if (ContentBinder != null)
			{
				ContentBinder.read(data, _content);
			}
			return data;
		}

		/// <see cref="BinderInterface.write()"/>
		public override string write(object _source)
		{
			if (ContentBinder != null)
			{
				object data = ContentBinder.getAffectedField(_source);
				//object data = FieldAccess.getField(_source, FieldName);
				return ContentBinder.write(data);
			}
			return "";
		}
	}
}
