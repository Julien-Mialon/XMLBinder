package storm.xmlbinder.binder;

import org.w3c.dom.Document;
import org.w3c.dom.Node;

import storm.xmlbinder.XmlBinderException;

/**
 * Class to bind xml tag to an object and add it to a collection.
 * 
 * @author Storm <j-storm@hotmail.fr>
 */
public class CollectionObjectBinder extends AbstractCollectionBinder 
{
	/**
	 * The name of the object class to create.
	 */
	protected String m_className = "";
	
	/**
	 * The content binder instance if needed.
	 */
	protected ContentBinder m_contentBinder = null;
	
	/**
	 * Construct an instance without content binder.
	 * Considering that the xml tag is not a text node and have child element.
	 * @param _fieldName : the name of the collection field.
	 * @param _className : the name of the class to create object.
	 */
	public CollectionObjectBinder(String _fieldName, String _className) 
	{
		super(_fieldName);
		this.m_className = _className;
	}
	
	/**
	 * Construct an instance with a content binder.
	 * Consider that the xml element is a text node.
	 * @param _fieldName : the name of the collection field.
	 * @param _className : the name of the class to create object.
	 * @param _contentBinder : the content binder to use.
	 */
	public CollectionObjectBinder(String _fieldName, String _className, ContentBinder _contentBinder)
	{
		this(_fieldName, _className);
		this.m_contentBinder = _contentBinder;
	}
	
	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.binder.AbstractBinder#read(java.lang.Object, java.lang.String)
	 */
	@Override
	public Object read(Object _data, String _content) throws XmlBinderException 
	{
		Object newData = createObject(this.m_className);
		add(newData, _data, this.m_fieldName);
		
		if(this.m_contentBinder != null)
		{
			m_contentBinder.read(newData, _content);
		}
		
		return newData;
	}

	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.binder.AbstractBinder#write(java.lang.Object, org.w3c.dom.Node, org.w3c.dom.Document)
	 */
	@Override
	public void write(Object _data, Node _node, Document _document) throws XmlBinderException 
	{
		ObjectBinder obj = new ObjectBinder(this.m_fieldName, this.m_className, this.m_contentBinder);
		obj.write(_data, _node, _document);
	}

}
