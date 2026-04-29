namespace KursovayaOOP
{
    public partial class Graphs : Form
    {
        private AbstractGraph? _graph = null;

        public Graphs()
        {
            InitializeComponent();
        }

        private void DrawGraphs()
        {
            Bitmap bmp = new(pictureBoxGraphs.Width, pictureBoxGraphs.Height);
            Graphics g = Graphics.FromImage(bmp);
            pictureBoxGraphs.Image = bmp;
        }
    }
}
