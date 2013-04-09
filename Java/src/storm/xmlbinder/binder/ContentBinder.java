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
import storm.xmlbinder.transformer.TransformerInterface;

/**
 * Binder to bind content of a xml tag to a field.
 *
 * @author Storm <j-storm@hotmail.fr>
 */
public class ContentBinder extends AbstractBinder
{
	/**
	 * The transformer to apply on data before storing it.
	 */
	protected TransformerInterface m_transformer = null;

	/**
	 * Construct an instance of the binder.
	 *
	 * @param _fieldName   : the name of the field.
	 * @param _transformer : the transformer instance to use.
	 */
	public ContentBinder(String _fieldName, TransformerInterface _transformer)
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
		Object processedContent = this.m_transformer.read(_content);
		setField(_data, this.m_fieldName, processedContent);
		return _data;
	}

	/*
	 * (non-Javadoc)
	 * @see storm.xmlbinder.binder.AbstractBinder#write(java.lang.Object, org.w3c.dom.Node, org.w3c.dom.Document)
	 */
	@Override
	public void write(Object _data, Node _node, Document _document) throws XmlBinderException
	{
		String resultString = "";
		if (_data != null)
		{
			resultString = this.m_transformer.write(_data);
		}
		_node.appendChild(_document.createTextNode(resultString));
	}

}
