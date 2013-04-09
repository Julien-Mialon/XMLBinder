package storm.xmlbinder;

/**
 * Class to avoid lib dependency problem while transmitting attribute from reader/writer to XmlElement.
 *
 * @author Storm <j-storm@hotmail.fr>
 */
public class XmlInternalAttribute
{
	/**
	 * The name of the attribute.
	 */
	protected String m_identifier;

	/**
	 * The value of the attribute.
	 */
	protected String m_value;

	/**
	 * Construct a new attribute with name and value.
	 *
	 * @param _identifier : the name of the attribute.
	 * @param _value      : the value of the attribute.
	 */
	public XmlInternalAttribute(String _identifier, String _value)
	{
		super();
		this.m_identifier = _identifier;
		this.m_value = _value;
	}

	/**
	 * Method to get the name of the attribute.
	 *
	 * @return the name of the attribute.
	 */
	public String getIdentifier()
	{
		return this.m_identifier;
	}

	/**
	 * Method to get the value of the attribute.
	 *
	 * @return the value of the attribute.
	 */
	public String getValue()
	{
		return this.m_value;
	}
}
