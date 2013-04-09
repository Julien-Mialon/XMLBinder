using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Exception
{
	/// <summary>
	/// Base class for all exception relative to XmlBinder component.
	/// </summary>
	public class XmlBinderException : FormatException
	{
		public XmlBinderException()
		{ 
		
		}

		public XmlBinderException(string _message)
			: base(_message)
		{

		}

		public XmlBinderException(string _class, string _function, string _message)
			: base(_class + "." + _function + "() : " + _message)
		{

		}
	}
}
