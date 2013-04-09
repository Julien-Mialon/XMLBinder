using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Exception
{
	/// <summary>
	/// Exception rose by the XmlElement class if an error happened.
	/// </summary>
	public class XmlElementException : XmlBinderException
	{
		public XmlElementException()
		{ 
		
		}

		public XmlElementException(string _message)
			: base(_message)
		{

		}

		public XmlElementException(string _class, string _function, string _message)
			: base(_class, _function, _message)
		{

		}
	}
}
