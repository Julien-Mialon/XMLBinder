using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XmlBinder.Binder
{
	/// <summary>
	/// Binder to ignore the xml tag.
	/// </summary>
	public class NullBinder : XmlBinder.Abstract.AbstractBinder
	{
		/// <summary>
		/// Create a NullBinder which will do nothing.
		/// </summary>
		public NullBinder() : base("")
		{

		}

		public override object read(object _source, string _content)
		{
			return _source;
		}

		public override string write(object _source)
		{
			return "";
		}
	}
}
