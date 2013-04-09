package storm.xmlbinder.transformer;

/**
 * Class to transform String to String and vice-versa.
 * @author Storm <j-storm@hotmail.fr>
 *
 */
public class StringTransformer implements TransformerInterface 
{
	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.transformer.TransformerInterface#read(java.lang.String)
	 */
	public Object read(String _value) 
	{
		return _value;
	}

	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.transformer.TransformerInterface#write(java.lang.Object)
	 */
	public String write(Object _value) 
	{
		return (String)_value;
	}
}
