using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KursovayaOOP
{
	public abstract class AbstractGraph<T>
		where T : IGraphCollection
	{
		protected T? Points;

		public abstract void addEdge(GraphEntity pointOf, GraphEntity pointTo, int value);

		public abstract void addEdge(int pointOf,int pointTo,int value);

		public abstract void removeEdge(int pointOf,int pointTo);

		public abstract void removeEdge(GraphEntity pointOf, GraphEntity pointTo);

		public abstract void addPoint(GraphEntity entity);

		public abstract void addPoint();

		public abstract void removePoint(GraphEntity entity);

		public abstract void removePoint(int pointNumber);
	}
}
