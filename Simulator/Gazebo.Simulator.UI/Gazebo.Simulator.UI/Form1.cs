using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Gazebo.Simulator.Interop;

namespace Gazebo.Simulator.UI
{
    public partial class Form1 : Form
    {
        private const int NLeds = 4;

        private DisplayModel displayModel;

        public Form1()
        {
            this.displayModel = new DisplayModel(Form1.NLeds);

            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // XXXX TEST
            Native.GetNextOpFn getNextOp = () => { return 0; };
            Native.SetLedFn setLed = this.UpdateLed;
            Native.LatchLedsFn latchLeds = this.DrawLeds;

            Native.GzEngineInit(getNextOp, setLed, latchLeds);
            Task.Run(() =>
            {
                //Task.Delay(2000);
                Native.GzEngineRun();
            });
        }

        private int UpdateLed(int n, byte r, byte g, byte b)
        {
            this.displayModel[n] = Color.FromArgb(r, g, b);

            return 0;
        }

        private void DrawLeds()
        {
            Graphics g = this.pbLeds.CreateGraphics();

            for (int i = 0; i < Form1.NLeds; i++)
            {
                SolidBrush fill = new SolidBrush(this.displayModel[i]);
                g.FillEllipse(fill, 50, (i * 75) + 25, 50, 50);
            }
        }
    }
}
