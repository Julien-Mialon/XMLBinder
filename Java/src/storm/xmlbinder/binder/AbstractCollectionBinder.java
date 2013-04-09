package storm.xmlbinder.binder;

import java.util.Collection;

import storm.xmlbinder.XmlBinderException;

/**
 * Abstract class for all CollectionBinder class.
 * Provide some useful method.
 * @author Storm <j-storm@hotmail.fr>
 */
public abstract class AbstractCollectionBinder extends AbstractBinder 
{
	/**
	 * Constructor to initialize super class with the field name.
	 * @param _fieldName : the name of the field.
	 */
	protected AbstractCollectionBinder(String _fieldName) 
	{
		super(_fieldName);
	}
	
	/**
	 * Method to add an element to the specified collection field. 
	 * @param _object : the object to add to the collection.
	 * @param _data : the data object.
	 * @param _fieldName : the name of the collection field. 
	 * @throws XmlBinderException
	 */
	protected void add(Object _object, Object _data, String _fieldName) throws XmlBinderException
	{
		@SuppressWarnings("unchecked")
		Collection<Object> collection = (Collection<Object>) getField(_data, _fieldName);
		collection.add(_object);
	}
}
