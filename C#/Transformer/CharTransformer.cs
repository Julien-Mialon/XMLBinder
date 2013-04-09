using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using XmlBinder.Exception;

namespace XmlBinder.Transformer
{
	public class CharTransformer : XmlBinder.Interface.TransformerInterface
	{
		public static CharTransformer Instance = new CharTransformer();

		public object read(string _value)
		{
			if (_value.Length != 1)
			{
				throw new TransformerException("CharTransformer", "read", "too many character in string to convert in char");
			}
			return _value[0];
		}

		public string write(object _value)
		{
			if (_value is char)
			{
				return "" + (char)_value;
			}
			else
			{
				throw new TransformerException("CharTransformer", "write", "the object of type " + _value.GetType().ToString() + " is not a char");
			}
		}
	}
}
