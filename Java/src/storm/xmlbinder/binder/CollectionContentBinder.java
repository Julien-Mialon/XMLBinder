package storm.xmlbinder.binder;

import org.w3c.dom.Document;
import org.w3c.dom.Node;

import storm.xmlbinder.XmlBinderException;
import storm.xmlbinder.transformer.TransformerInterface;

/**
 * This class bind content of a xml tag to a collection using a transformer
 * to convert data to the right format.
 * @author Storm <j-storm@hotmail.fr>
 */
public class CollectionContentBinder extends AbstractCollectionBinder 
{	
	/**
	 * The transformer to use.
	 */
	protected TransformerInterface m_transformer = null;
	
	/**
	 * construct an instance of the class.
	 * @param _fieldName : the name of the collection field.
	 * @param _transformer : the transformer instance to use to convert data before storing it.
	 */
	public CollectionContentBinder(String _fieldName, TransformerInterface _transformer)
	{
		super(_fieldName);
		this.m_transformer = _transformer;
	}
	
	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.binder.AbstractBinder#read(java.lang.Object, java.lang.String)
	 */
	@Override
	public Object read(Object _data, String _content) throws XmlBinderException 
	{
		add(this.m_transformer.read(_content), _data, this.m_fieldName);
		
		return _data;
	}

	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.binder.AbstractBinder#write(java.lang.Object, org.w3c.dom.Node, org.w3c.dom.Document)
	 */
	@Override
	public void write(Object _data, Node _node, Document _document) throws XmlBinderException 
	{
		ContentBinder obj = new ContentBinder(this.m_fieldName, this.m_transformer);
		obj.write(_data, _node, _document);
	}

}
