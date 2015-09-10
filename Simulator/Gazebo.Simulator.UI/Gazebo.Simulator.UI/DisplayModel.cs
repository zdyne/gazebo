using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gazebo.Simulator.UI
{
    internal sealed class DisplayModel
    {
        private IList<Led> leds;

        public DisplayModel(int nLeds)
        {
            this.leds = new List<Led>();

            for (int i = 0; i < nLeds; i++)
            {
                this.leds.Add(new Led(Color.White));
            }
        }

        public Color this[int idx]
        {
            get { return this.leds[idx].Color; }

            set { this.leds[idx].Color = value; }
        }
    }
}
