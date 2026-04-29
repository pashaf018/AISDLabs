using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KursovayaOOP
{
	public class GraphEntity
	{
		private int _PosX;

		private int _PosY;

		public int Size { get; set; }

		public Color Color { get; set; }

		public int Number { get; set; }

		public GraphEntity(int x,int y,int size,Color color,int number)
		{
			setPosition(x,y);
			Size = size;
			Color = color;
			Number = number;
		}

		public void setPosition(int x,int y)
		{
			_PosX = x;
			_PosY = y;
		}
	}
}
