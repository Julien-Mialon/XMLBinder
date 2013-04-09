package storm.xmlbinder.transformer;

/**
 * Class to turn integer to String and vice versa.
 * @author Storm <j-storm@hotmail.fr>
 *
 */
public class IntegerTransformer implements TransformerInterface
{
	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.transformer.TransformerInterface#read(java.lang.String)
	 */
	public Object read(String _value)
	{
		return Integer.parseInt(_value);
	}

	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.transformer.TransformerInterface#write(java.lang.Object)
	 */
	public String write(Object _value)
	{
		return _value.toString();
	}

}
