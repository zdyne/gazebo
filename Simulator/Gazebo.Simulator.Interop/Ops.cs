using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gazebo.Simulator.Interop
{
    public static class Ops
    {
        public const byte Halt = 0x00;
        public const byte Descriptor = 0x01;
        public const byte Color = 0x02;
        public const byte AllOn = 0x03;
        public const byte Delay = 0x04;
    }
}
