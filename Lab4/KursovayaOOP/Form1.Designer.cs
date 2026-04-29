namespace KursovayaOOP
{
    partial class Graphs
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

		#region Windows Form Designer generated code

		/// <summary>
		///  Required method for Designer support - do not modify
		///  the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			pictureBoxGraphs = new PictureBox();
			panelTools = new Panel();
			((System.ComponentModel.ISupportInitialize)pictureBoxGraphs).BeginInit();
			SuspendLayout();
			// 
			// pictureBoxGraphs
			// 
			pictureBoxGraphs.Dock = DockStyle.Right;
			pictureBoxGraphs.Location = new Point(200, 0);
			pictureBoxGraphs.Name = "pictureBoxGraphs";
			pictureBoxGraphs.Size = new Size(600, 450);
			pictureBoxGraphs.TabIndex = 0;
			pictureBoxGraphs.TabStop = false;
			// 
			// panelTools
			// 
			panelTools.BorderStyle = BorderStyle.FixedSingle;
			panelTools.Dock = DockStyle.Left;
			panelTools.Location = new Point(0, 0);
			panelTools.Name = "panelTools";
			panelTools.Size = new Size(200, 450);
			panelTools.TabIndex = 1;
			// 
			// Form1
			// 
			AutoScaleDimensions = new SizeF(7F, 15F);
			AutoScaleMode = AutoScaleMode.Font;
			ClientSize = new Size(800, 450);
			Controls.Add(panelTools);
			Controls.Add(pictureBoxGraphs);
			Name = "Form1";
			Text = "Form1";
			((System.ComponentModel.ISupportInitialize)pictureBoxGraphs).EndInit();
			ResumeLayout(false);
		}

		#endregion

		private PictureBox pictureBoxGraphs;
		private Panel panelTools;
	}
}
