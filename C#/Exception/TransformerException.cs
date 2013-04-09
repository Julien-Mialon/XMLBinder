using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Exception
{
	/// <summary>
	/// Exception rose when an error happened with transformer.
	/// </summary>
    public class TransformerException : XmlBinderException
    {
        public TransformerException()
		{ 
		
		}

		public TransformerException(string _message)
			: base(_message)
		{

		}

        public TransformerException(string _class, string _function, string _message)
			: base(_class, _function, _message)
		{

		}
    }
}
