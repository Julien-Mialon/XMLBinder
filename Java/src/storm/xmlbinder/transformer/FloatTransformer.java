package storm.xmlbinder.transformer;

public class FloatTransformer implements TransformerInterface
{
	public Object read(String _value)
	{
		return Float.parseFloat(_value);
	}

	public String write(Object _value)
	{
		return _value.toString();
	}

}
