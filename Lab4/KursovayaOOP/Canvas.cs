using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KursovayaOOP
{
	public class Canvas 
	{
		public int Width { get; init; }

		public int Height { get; init; }

		public Canvas(int width,int height)
		{
			if(Width <= 0 || Height <= 0)
			{
				return;
			}
			Width = width;
			Height = height;
		}

		public void DrawPoint
	}
}
