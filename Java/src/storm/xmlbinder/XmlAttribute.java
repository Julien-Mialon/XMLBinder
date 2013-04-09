package storm.xmlbinder;

import org.w3c.dom.Element;
import storm.xmlbinder.transformer.TransformerInterface;

import java.lang.reflect.Field;

/**
 * This class represent an attribute of an xml node.
 * Used to bind attribute content with data model.
 *
 * @author Storm <j-storm@hotmail.fr>
 */
public class XmlAttribute
{

	/**
	 * The name of the attribute.
	 */
	protected String m_identifier = "";

	/**
	 * The transformer to apply on the data before storing them.
	 */
	protected TransformerInterface m_transformer = null;

	/**
	 * Field name to store and read data value.
	 */
	protected String m_fieldName = "";

	/**
	 * Construct an instance of attribute with the specified name and binder.
	 *
	 * @param _identifier  : the name of the attribute.
	 * @param _transformer : the transformer to use.
	 */
	public XmlAttribute(String _identifier, String _fieldName, TransformerInterface _transformer)
	{
		super();
		this.m_identifier = _identifier;
		this.m_fieldName = _fieldName;
		this.m_transformer = _transformer;
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
	 * Method to read a xml attribute and store it using defined rule.
	 */
	public void read(Object _data, String _value) throws XmlBinderException
	{
		setField(_data, this.m_fieldName, this.m_transformer.read(_value));
	}

	/**
	 * Method to write the xml attribute.
	 *
	 * @param _data        : the current data object.
	 * @param _currentNode : the current xml node.
	 * @throws XmlBinderException
	 */
	public void write(Object _data, Element _currentNode) throws XmlBinderException
	{
		_currentNode.setAttribute(this.m_identifier, this.m_transformer.write(getField(_data, this.m_fieldName)));
	}

	/**
	 * Method to change the value of a field based on its name in a String format.
	 *
	 * @param _data      : the data object.
	 * @param _fieldName : the name of the field.
	 * @param _value     : the new value of the field.
	 * @throws XmlBinderException
	 */
	protected void setField(Object _data, String _fieldName, Object _value) throws XmlBinderException
	{
		try
		{
			if (_data != null)
			{
				Field f = _data.getClass().getField(_fieldName);
				f.set(_data, _value);
			}
		}
		catch (Exception ex)
		{
			throw new XmlBinderException();
		}
	}

	/**
	 * Method to get a field value based on the field name under String format.
	 *
	 * @param _data      : the data object.
	 * @param _fieldName : the name of the field.
	 * @return the value of the field.
	 * @throws XmlBinderException
	 */
	protected Object getField(Object _data, String _fieldName) throws XmlBinderException
	{
		try
		{
			if (_data != null)
			{
				Field f = _data.getClass().getField(_fieldName);
				return f.get(_data);
			}
			return null;
		}
		catch (Exception ex)
		{
			throw new XmlBinderException();
		}
	}
}
