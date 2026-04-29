using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KursovayaOOP
{
	public class ListWeightedAdj : IGraphCollection
	{
		private List<List<KeyValuePair<GraphEntity,int>>> Points;

		public ListWeightedAdj()
		{
			Points = new List<List<KeyValuePair<GraphEntity, int>>>();
		}

		public int tryAddPoint()
		{
			Points.Add(new List<KeyValuePair<GraphEntity,int>>());
			return Points.Count - 1;
		}

		public bool tryRemovePoint(int index)
		{
			if(index < 0 || Points.Count <= index)
			{
				return false;
			}

			for(int i = 0;i < Points[index].Count;i++)
			{
				Points[Points[index][i].Key.Number].RemoveAll(p => p.Key.Number == index);
			}

			Points.RemoveAt(index);
			return true;
		}

		public bool tryAddEdge(int from,int to,int value)
		{
			if(from < 0 || Points.Count <= from || to < 0 || Points.Count <= to || value <= 0)
			{
				return false;
			}

			Points[from].Add(new KeyValuePair<GraphEntity, int>(Points[from],value));
			Points[to].Add(new KeyValuePair<GraphEntity, int>(from, value));
			return true;
		}

		/// <summary>
		/// Removes the first edge that contains these two points
		/// </summary>
		/// <param name="from"></param>
		/// <param name="to"></param>
		/// <returns></returns>
		public bool tryRemoveEdge(int from,int to)
		{
			if(from < 0 || Points.Count <= from || to < 0 || Points.Count <= to)
			{
				return false;
			}

			if (!Points[from].Any(p => p.Key == to))
			{
				return false;
			}

			Points[from].Remove(Points[from].Find(p => p.Key == to));
			Points[to].Remove(Points[to].Find(p => p.Key == from));
			return true;
		}

		/// <summary>
		/// Removes the first edge that contains these two points with a specific weight
		/// </summary>
		/// <param name="from"></param>
		/// <param name="to"></param>
		/// <param name="value"></param>
		/// <returns></returns>
		public bool tryRemoveEdge(int from,int to,int value)
		{
			if (from < 0 || Points.Count <= from || to < 0 || Points.Count <= to)
			{
				return false;
			}

			if (!Points[from].Any(p => p.Key == to && p.Value == value))
			{
				return false;
			}

			Points[from].Remove(Points[from].Find(p => p.Key == to && p.Value == value));
			Points[to].Remove(Points[to].Find(p => p.Key == from && p.Value == value));
			return true;
		}

		public int Size() => Points.Count;
	}
}
