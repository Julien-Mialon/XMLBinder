using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using XmlBinder.Exception;
using XmlBinder.Tools;

namespace XmlBinder
{
	/// <summary>
	/// Class to read xml file and bind the content to object.
	/// This process use binder system to associate data from the xml file
	/// to objects properties.
	/// This binding system used is the same that is in XmlWriter.
	/// <see cref="XmlWriter"/>
	/// </summary>
	public class XmlReader
	{
		/// <summary>
		/// List of all root element which have been registered.
		/// A root element is the first element in an xml file.
		/// </summary>
		protected List<XmlElement> m_rootElement = new List<XmlElement>();

		/// <summary>
		/// Construct an XmlReader with only one root element available.
		/// </summary>
		/// <param name="_root">The root element to use for binding process.</param>
		public XmlReader(XmlElement _root)
		{
			this.m_rootElement.Add(_root);
		}

		/// <summary>
		/// Construct an XmlReader with multiple root element available.
		/// This could be use if you have multiple content available.
		/// </summary>
		/// <param name="_roots">The list of all available root elements.</param>
		public XmlReader(List<XmlElement> _roots)
		{
			this.m_rootElement.AddRange(_roots);
		}

		/// <summary>
		/// Method to parse and bind xml file using rules defined in root elements.
		/// </summary>
		/// <param name="_inputStream">Stream to the Xml file to read.</param>
		/// <returns>Root data object created by xml file binding process.</returns>
		/// <exception cref="XmlBinderException">If the file is not readable or an error happened in binding process</exception>
		public object Read(System.IO.Stream _inputStream)
		{
			System.Xml.XmlReader file = null;

            XmlElement currentElement = new XmlElement();
            object currentData = null;
            Stack<XmlElement> xmlElements = new Stack<XmlElement>();
            Stack<object> datas = new Stack<object>();

			try
			{
				file = System.Xml.XmlReader.Create(_inputStream);
			}
			catch (System.Exception e)
			{
				throw new XmlBinderException("XmlReader", "Read", "Unable to open the file " + e.ToString());
			}
			try
			{
				foreach (XmlElement e in m_rootElement)
				{
					currentElement.addChild(e);
				}


				bool continueWithoutReadNext = false;
				while (continueWithoutReadNext || file.Read())
				{
					continueWithoutReadNext = false;
					if (file.NodeType == XmlNodeType.Element)
					{
						XmlElement child = getXmlElementWithName(currentElement, file.Name);
						if (child != null)
						{
							List<XmlAttributeData> attributes = new List<XmlAttributeData>();
							if (file.HasAttributes)
							{
								for (int i = 0; i < file.AttributeCount; ++i)
								{
									file.MoveToAttribute(i);
									attributes.Add(new XmlAttributeData(file.Name, file.Value));
								}
							}							

							if (currentData != null)
							{
								datas.Push(currentData);
								xmlElements.Push(currentElement);
							}

							file.Read();
							if (!file.HasValue)
							{
								continueWithoutReadNext = true;
							}

							currentData = child.read(currentData, file.Value, attributes);
							currentElement = child;
						}
						else
						{
							throw new XmlBinderException("XmlReader", "Read", "Unable to bind tag " + file.Name);
						}
					}
					else if (file.NodeType == XmlNodeType.EndElement)
					{
						if (currentElement.Identifier == file.Name)
						{
							if (datas.Count == 0)
								return currentData;

							currentElement = xmlElements.Pop();
							currentData = datas.Pop();
						}
						else
						{
							throw new XmlBinderException("XmlReader", "Read", "Unable to handle close tag " + file.Name);
						}
					}
				}
			}
			catch (System.Exception e)
			{
				throw new XmlBinderException("XmlReader", "Read", "error " + e.ToString());
			}
			return currentData;
		}

		/// <summary>
		/// Method to get the XmlElement in child of another with the specified tag name.
		/// </summary>
		/// <param name="_ancestor">The ancestor where to look for child.</param>
		/// <param name="_name">The xml tag name to look for.</param>
		/// <returns>The XmlElement's child if exists, null otherwise.</returns>
        protected XmlElement getXmlElementWithName(XmlElement _ancestor, string _name)
        {
            foreach (XmlElement e in _ancestor.Children)
            {
                if (e.Identifier == _name)
                {
                    return e;
                }
            }
            return null;
        }
	}
}
