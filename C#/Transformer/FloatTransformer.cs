using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Exception;

namespace XmlBinder.Transformer
{
	/// <summary>
	/// Transformer class to turn xml input to float.
	/// </summary>
    public class FloatTransformer : XmlBinder.Interface.TransformerInterface
    {
		public static FloatTransformer Instance = new FloatTransformer();

		public object read(string _value)
		{
			float n;
			if (float.TryParse(_value, out n))
			{
				return n;
			}
			else
			{
				throw new TransformerException("FloatTransformer", "read", "unable to parse " + _value + " to float.");
			}
		}

		public string write(object _value)
		{
			if (_value is float)
			{
				return ((float)_value).ToString();
			}
			else
			{
				throw new TransformerException("FloatTransformer", "write", "the object of type " + _value.GetType().ToString() + " is not a float");
			}
		}
    }
}
