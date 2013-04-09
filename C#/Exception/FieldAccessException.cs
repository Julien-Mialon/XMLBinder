using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Exception
{
	/// <summary>
	/// Exception rose when an error happened while getting or setting field.
	/// </summary>
	public class FieldAccessException : XmlBinderException
	{
		public FieldAccessException()
		{ 
		
		}

		public FieldAccessException(string _message)
			: base(_message)
		{

		}

		public FieldAccessException(string _class, string _function, string _message)
			: base(_class, _function, _message)
		{

		}
	}
}
