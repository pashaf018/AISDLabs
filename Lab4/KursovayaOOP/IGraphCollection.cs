using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KursovayaOOP
{
	public interface IGraphCollection
	{
		public int tryAddPoint();

		public bool tryRemovePoint(int index);

		public bool tryAddEdge(int from, int to, int value);

		public bool tryRemoveEdge(int from, int to);

		public int Size();
	}
}
