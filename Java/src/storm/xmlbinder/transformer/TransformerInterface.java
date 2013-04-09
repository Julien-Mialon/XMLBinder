package storm.xmlbinder.transformer;

/**
 * This interface describe the needed function for a transformer.
 * 
 * @author Storm <j-storm@hotmail.fr>
 */
public interface TransformerInterface 
{
	/**
	 * Method to read a String value and transform it into the desired object.
	 * @param _value : the value to convert.
	 * @return the converted value.
	 */
	public Object read(String _value);
	/**
	 * Method to write an object to a string.
	 * @param _value : the value to convert to a string.
	 * @return the converted string.
	 */
	public String write(Object _value);
}
