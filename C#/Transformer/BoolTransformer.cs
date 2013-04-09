using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Exception;

namespace XmlBinder.Transformer
{
	/// <summary>
	/// Transformer class to turn xml input to boolean.
	/// </summary>
    public class BoolTransformer : XmlBinder.Interface.TransformerInterface
    {
		public static BoolTransformer Instance = new BoolTransformer();

        public object read(string _value)
        {
            int n;
            if (int.TryParse(_value, out n))
            {
				if (n == 0)
					return false;
				else if (n == 1)
					return true;
            }
            throw new TransformerException("BoolTransformer", "read", "unable to parse " + _value + " to bool.");
        }

        public string write(object _value)
        {
            if (_value is bool)
            {
                return ((bool)_value) ? "1" : "0";
            }
            else
            {
                throw new TransformerException("BoolTransformer", "write", "the object of type " + _value.GetType().ToString() + " is not a bool");
            }
        }
    }
}
