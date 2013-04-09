package storm.xmlbinder.binder;

import org.w3c.dom.Document;
import org.w3c.dom.Node;

import storm.xmlbinder.XmlBinderException;

/**
 * This binder just ignore the element.
 * Useful when child element is more useful.
 * 
 * @author Storm <j-storm@hotmail.fr>
 */
public class NullBinder extends AbstractBinder
{
	/**
	 * Construct an instance.
	 */
	public NullBinder()
	{
		super("");
	}

	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.binder.AbstractBinder#read(java.lang.Object, java.lang.String)
	 */
	@Override
	public Object read(Object _data, String _content) throws XmlBinderException
	{
		return _data;
	}

	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.binder.AbstractBinder#write(java.lang.Object, org.w3c.dom.Node, org.w3c.dom.Document)
	 */
	@Override
	public void write(Object _data, Node _node, Document _document) throws XmlBinderException
	{
		//do nothing
	}

}
