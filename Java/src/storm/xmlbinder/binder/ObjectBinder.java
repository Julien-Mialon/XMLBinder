/*
 * Copyright Julien Mialon, Millian Poquet, Soumia Betta, Tarik Abas.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

package storm.xmlbinder.binder;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import storm.xmlbinder.XmlBinderException;

/**
 * Binder to bind xml element to a new Object.
 *
 * @author Storm <j-storm@hotmail.fr>
 */
public class ObjectBinder extends AbstractBinder
{
	/**
	 * The name of the class to create the object.
	 */
	protected String m_className = "";

	/**
	 * The content binder to use if needed.
	 */
	protected ContentBinder m_contentBinder = null;

	/**
	 * Construct an instance without a content binder.
	 * Assuming that the xml element is not a text node and has child element.
	 *
	 * @param _fieldName : the name of the field.
	 * @param _className : the name of the class to create object.
	 */
	public ObjectBinder(String _fieldName, String _className)
	{
		super(_fieldName);
		this.m_className = _className;
	}

	/**
	 * Construct an instance with a content binder.
	 * Assuming that the xml element is a text node.
	 *
	 * @param _fieldName     : the name of the field.
	 * @param _className     : the name of the class to create object.
	 * @param _contentBinder : the content binder to use.
	 */
	public ObjectBinder(String _fieldName, String _className, ContentBinder _contentBinder)
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
		setField(_data, this.m_fieldName, newData);

		if (this.m_contentBinder != null)
		{
			this.m_contentBinder.read(newData, _content);
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
		//Xml element already created, just have to map the content binder if needed
		if (this.m_contentBinder != null)
		{
			this.m_contentBinder.write(_data, _node, _document);
		}
	}

}
