using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml;
using XmlBinder.Exception;

namespace XmlBinder
{
	/// <summary>
	/// Class to write xml file and bind object value to xml content.
	/// This process use binder system to associate data from the xml file
	/// to objects properties.
	/// This binding system used is the same that is in XmlReader.
	/// <see cref="XmlReader"/>
	/// </summary>
	public class XmlWriter
	{
		/// <summary>
		/// XmlElement rules to bind object value to xml content.
		/// </summary>
		protected XmlElement m_rootElement = null;

		/// <summary>
		/// Construct an XmlWriter with the specified binding rules.
		/// </summary>
		/// <param name="_rootElement">The rule to bind root element.</param>
		public XmlWriter(XmlElement _rootElement)
		{
			m_rootElement = _rootElement;
		}

		/// <summary>
		/// Method to write the data object to xml file using binding rules defined before.
		/// </summary>
		/// <param name="_outputStream">Stream to output xml file.</param>
		/// <param name="_baseData">The root data object to write to xml file.</param>
		/// <param name="_readableFormat">A boolean to enable readable xml file or not. This basically enable indentation or not.</param>
		/// <exception cref="XmlBinderException">If the file is not writable or if an error happened while binding.</exception>
		public void Write(Stream _outputStream, object _baseData, bool _readableFormat = true)
		{
			System.Xml.XmlWriter writer = null;
			//XmlTextWriter writer = null;
			try
			{
				System.Xml.XmlWriterSettings settings = new XmlWriterSettings();
				settings.Encoding = Encoding.UTF8;
				if (_readableFormat)
				{
					settings.Indent = true;
					settings.IndentChars = "\t";
				}
				settings.CloseOutput = true;
				settings.NewLineChars = "\n";
				settings.OmitXmlDeclaration = false;

				writer = System.Xml.XmlWriter.Create(_outputStream, settings);
			}
			catch (System.Exception e)
			{
				throw new XmlBinderException("XmlWriter", "Write", "unable to write xml file " + e.ToString());
			}

			try
			{
				writer.WriteStartDocument();

				m_rootElement.write(writer, _baseData);

				writer.WriteEndDocument();
			}
			finally
			{
				writer.Flush();
				writer.Dispose();
			}
		}
	}
}
