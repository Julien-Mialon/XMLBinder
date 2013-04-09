using System;
using System.Collections;
using System.Collections.Generic;
using System.Xml;
using XmlBinder.Abstract;
using XmlBinder.Exception;
using XmlBinder.Interface;
using XmlBinder.Tools;

namespace XmlBinder
{
	/// <summary>
	/// This class define rules to bind xml tag content.
	/// </summary>
	public class XmlElement
	{
		#region Class attributes
		/// <summary>
		/// Xml tag name which is related to this rule.
		/// </summary>
		protected string m_identifier = "";

		/// <summary>
		/// Binder to use to bind xml to object.
		/// </summary>
		protected BinderInterface m_binder = null;

		/// <summary>
		/// List of all xml children element.
		/// </summary>
		protected List<XmlElement> m_children = new List<XmlElement>();

		/// <summary>
		/// List of all xml attribute related to this xml element.
		/// </summary>
		protected List<XmlAttribute> m_attributes = new List<XmlAttribute>();
		#endregion

		#region Public field
		/// <summary>
		/// Name of the xml tag, it is case insensitive.
		/// </summary>
		public string Identifier 
		{
			get
			{
				return m_identifier;
			}
			set
			{
				m_identifier = value;
			}
		}

		/// <summary>
		/// Binder associated to this element.
		/// It will be used to read / write the element.
		/// </summary>
		public BinderInterface Binder
		{
			get
			{
				return m_binder;
			}
			set
			{
				m_binder = value;
			}
		}

		/// <summary>
		/// List of all children of this element.
		/// </summary>
		public List<XmlElement> Children
		{
			get
			{
				return m_children;
			}
		}

		/// <summary>
		/// List of all xml attributes of this element.
		/// </summary>
		public List<XmlAttribute> Attributes
		{
			get
			{
				return m_attributes;
			}
		}
		#endregion

		#region Constructor

		/// <summary>
		/// Construct an empty XmlElement.
		/// </summary>
        public XmlElement()
        {
        }

		/// <summary>
		/// Constructor of an XmlElement class.
		/// This constructor could throw an XmlBinder.Exception.XmlElementException if parameters are not correct.
		/// </summary>
		/// <param name="_identifier">Name of the xml tag.</param>
		/// <param name="_binder">Binder object to use to bind xml tag.</param>
		public XmlElement(string _identifier, BinderInterface _binder) 
		{
			if (_identifier == "")
			{
				throw new XmlElementException("XmlElement", "Constructor", "unable to create an XmlElement without an identifier.");
			}
			if (_binder == null)
			{
				throw new XmlElementException("XmlElement", "Constructor", "unable to create an XmlElement withour a binder.");
			}
			this.Identifier = _identifier;
			this.Binder = _binder;
		}

		#endregion

		#region Public Method

		/// <summary>
		/// Method to add a child element to this one.
		/// </summary>
		/// <param name="_child">The child to add to this element.</param>
		public void addChild(XmlElement _child)
		{
			this.Children.Add(_child);
		}

		/// <summary>
		/// Method to remove a child from this element.
		/// </summary>
		/// <param name="_child">The child to remove.</param>
		public void removeChild(XmlElement _child)
		{
			while(this.Children.Remove(_child));
		}

		/// <summary>
		/// Method to add an attribute rule to this element.
		/// </summary>
		/// <param name="_attribute">The attribute rule to add.</param>
		public void addAttribute(XmlAttribute _attribute)
		{
			this.Attributes.Add(_attribute);
		}

		/// <summary>
		/// Method to remove an attribute to this element.
		/// </summary>
		/// <param name="_attribute">The attribute rule to remove.</param>
		public void removeAttribute(XmlAttribute _attribute)
		{
			while(this.Attributes.Remove(_attribute));
		}

		/// <summary>
		/// Method to bind xml content to data object.
		/// </summary>
		/// <param name="_source">The object where to store data.</param>
		/// <param name="_xmlContent">The xml tag content.</param>
		/// <param name="_attributes">The attribute name value pair data.</param>
		/// <returns>The object created by the binding rule.</returns>
		public object read(object _source, string _xmlContent, List<XmlAttributeData> _attributes)
		{
            object newData = Binder.read(_source, _xmlContent);
            foreach (XmlAttribute attr in Attributes)
            {
                XmlAttributeData attrData = getAttributeByName(_attributes, attr.Identifier);
                if (attrData == null)
                {
                    throw new XmlElementException("XmlElement", "read", "Error : no attribute " + attr.Identifier + " in tag " + Identifier);
                }
                attr.read(newData, attrData.Value);
            }
			return newData;
		}

		/// <summary>
		/// Method to write object content to xml file.
		/// </summary>
		/// <param name="_writer">XmlWriter to use to write to the file.</param>
		/// <param name="_data">The object which will be wrote.</param>
		public void write(System.Xml.XmlWriter _writer, object _data)
		{
			//ecriture binder
			if (Binder is AbstractCollectionBinder)
			{
				IList collection = (IList)Binder.getAffectedField(_data);
				foreach (object c in collection)
				{
					writeElement(_writer, c);
				}
			}
			else
			{
				writeElement(_writer, Binder.getAffectedField(_data));
			}
		}

		#endregion

		#region Protected Method

		/// <summary>
		/// Retrieve the pair of name and value of an attribute in a list of pair.
		/// </summary>
		/// <param name="_attributes">The list of attributes.</param>
		/// <param name="_attributeName">The name of the attribute to look for.</param>
		/// <returns>The found attribute or null.</returns>
        XmlAttributeData getAttributeByName(List<XmlAttributeData> _attributes, string _attributeName)
        {
            foreach (XmlAttributeData attr in _attributes)
            {
                if (attr.Identifier == _attributeName)
                {
                    return attr;
                }
            }
            return null;
        }

		/// <summary>
		/// Sub method of write process to write an element.
		/// </summary>
		/// <param name="_writer">XmlWriter to use to write file.</param>
		/// <param name="_data">The object to write, it must be the affected field of the binder.</param>
		protected void writeElement(System.Xml.XmlWriter _writer, object _data)
		{
			_writer.WriteStartElement(Identifier);

			//ecriture attribut
			foreach (XmlAttribute attr in Attributes)
			{
				attr.write(_writer, _data);
			}

			//ecriture binder
			_writer.WriteValue(Binder.write(_data));

			//ecriture enfant
			foreach (XmlElement child in Children)
			{
				//CHECK
				child.write(_writer, _data);
			}

			_writer.WriteEndElement();
		}

		#endregion
	}
}
