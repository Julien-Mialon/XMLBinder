using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Exception;

namespace XmlBinder.Transformer
{
	/// <summary>
	/// Transformer class to turn xml input into int.
	/// </summary>
    public class IntTransformer : XmlBinder.Interface.TransformerInterface
    {
		public static IntTransformer Instance = new IntTransformer();

        public object read(string _value)
        {
            int n;
            if (int.TryParse(_value, out n))
            {
                return n;
            }
            else
            {
                throw new TransformerException("IntTransformer", "read", "unable to parse " + _value + " to int.");
            }
        }

        public string write(object _value)
        {
            if (_value is int)
            {
                return ((int)_value).ToString();
            }
            else
            {
                throw new TransformerException("IntTransformer", "write", "the object of type " + _value.GetType().ToString() + " is not an int");
            }
        }
    }
}
