using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gazebo.Simulator.UI
{
    internal sealed class Led
    {
        public Led(Color c) : base()
        {
            this.Color = c;
        }

        public Color Color
        {
            get; set;
        }
    }
}
