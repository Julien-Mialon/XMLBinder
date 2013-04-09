package storm.xmlbinder.binder;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import storm.xmlbinder.XmlBinderException;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;


/**
 * Base class for xml content binder.
 * All binders must extend this base class.
 *
 * @author Storm <j-storm@hotmail.fr>
 */
public abstract class AbstractBinder
{
	/**
	 * The name of the affected field.
	 */
	protected String m_fieldName;

	/**
	 * Base constructor of the class, set the name of the field.
	 *
	 * @param _fieldName : the name of the field.
	 */
	protected AbstractBinder(String _fieldName)
	{
		super();
		this.m_fieldName = _fieldName;
	}

	/**
	 * Method to read a value and store it to the data object.
	 *
	 * @param _data    : the data object.
	 * @param _content : the value.
	 * @return the created data object or it is parent if it is the same.
	 * @throws XmlBinderException
	 */
	public abstract Object read(Object _data, String _content) throws XmlBinderException;

	/**
	 * Method to write a value under xml format.
	 *
	 * @param _data     : the data object.
	 * @param _node     : the current xml node.
	 * @param _document : the xml document to create xml elements.
	 * @throws XmlBinderException
	 */
	public abstract void write(Object _data, Node _node, Document _document) throws XmlBinderException;

	/**
	 * Method to create object based on its class name.
	 *
	 * @param _className : the name of the object class.
	 * @return the new object.
	 * @throws XmlBinderException
	 */
	protected Object createObject(String _className) throws XmlBinderException
	{
		try
		{
			Class<?> cs = Class.forName(_className);
			Constructor<?> cr = cs.getConstructor();
			return cr.newInstance();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
			throw new XmlBinderException();
		}
	}

	/**
	 * Method to set the value of a field based on its name under String format.
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
				Field f = _data.getClass().getDeclaredField(_fieldName);
				f.setAccessible(true);
				f.set(_data, _value);
			}
		}
		catch (Exception ex)
		{
			throw new XmlBinderException();
		}
	}

	/**
	 * Method to get the current value of a field based on its name under String format.
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
			if (_data != null && !_fieldName.isEmpty())
			{
				Field f = _data.getClass().getDeclaredField(_fieldName);
				f.setAccessible(true);
				return f.get(_data);
			}
			return _data;
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
			throw new XmlBinderException();
		}
	}

	/**
	 * Method to retrieve the value of the field affected by this Binder.
	 *
	 * @param _data : the data object.
	 * @return the value of the field.
	 * @throws XmlBinderException
	 */
	public Object getAffectedField(Object _data) throws XmlBinderException
	{
		return getField(_data, this.m_fieldName);
	}
}
