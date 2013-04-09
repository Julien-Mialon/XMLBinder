using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Exception;

namespace XmlBinder.Transformer
{
	/// <summary>
	/// Transformer class to turn xml input to string and vice-versa.
	/// </summary>
    public class StringTransformer : XmlBinder.Interface.TransformerInterface
    {
		public static StringTransformer Instance = new StringTransformer();

        public object read(string _value)
        {
            return _value;
        }

        public string write(object _value)
        {
            if (_value is string)
            {
                return (string)_value;
            }
            else
            {
                throw new TransformerException("StringTransformer", "write", "the object of type " + _value.GetType().ToString() + " is not a string");
            }
        }
    }
}
