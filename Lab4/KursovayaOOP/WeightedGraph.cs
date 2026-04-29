using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KursovayaOOP
{
	public class WeightedGraph<T> : AbstractGraph<T>
		where T : IGraphCollection
	{
		private Canvas _canvas;

		public WeightedGraph(int width,int height)
		{
			_canvas = new Canvas(width, height);
		}

		public override void addEdge(GraphEntity pointOf, GraphEntity pointTo, int value)
		{
			
		}

		public override void addEdge(int pointOf, int pointTo, int value) => Points.tryAddEdge(pointOf, pointTo, value);

		public override void removeEdge(int pointOf, int pointTo)
		{
			if(Points == null)
			{
				return;
			}

		}

		public override void removeEdge(GraphEntity pointOf, GraphEntity pointTo)
		{
			if (Points == null)
			{
				return;
			}
			Points.tryRemoveEdge(pointOf.Number, pointTo.Number);
		}

		public override void addPoint()
		{
			if(Points == null)
			{
				return;
			}
			Random rand = new Random();
			GraphEntity entity = new GraphEntity(rand.Next(0, _canvas.Width), rand.Next(0, _canvas.Height),rand.Next(0,100),
				Color.FromArgb(rand.Next(0, 256), rand.Next(0, 256), rand.Next(0, 256)),
				Points.tryAddPoint());
			_entities.Add(entity);
		}

		public override void addPoint(GraphEntity entity)
		{
			if(Points == null)
			{
				return;
			}
			entity.Number = Points.tryAddPoint();
			_entities.Add(entity);
		}

		public override void removePoint(int pointNumber)
		{
			if(Points == null)
			{
				return;
			}
			_entities.Remove(_entities.Find(e => e.Number == pointNumber));
			Points.tryRemovePoint(pointNumber);
		}

		public override void removePoint(GraphEntity entity)
		{
			if(Points == null)
			{
				return;
			}
			_entities.Remove(entity);
			Points.tryRemovePoint(entity.Number);
		}

		public int DjikstraAlgorithm(int from,int to)
		{
			if(from < 0 || to < 0 || from > Points.Size() || to > Points.Size())
			{
				return 0;
			}

			int[] ranges = new int[Points.Size()];
			Array.Fill(ranges, int.MaxValue);
			ranges[from] = 0;
			bool[] visited = new bool[Points.Size()];
			Array.Fill(visited, false);


			return 0;
		}
	}
}
