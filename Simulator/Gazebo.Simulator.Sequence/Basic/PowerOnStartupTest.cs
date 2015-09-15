using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Gazebo.Simulator.Interop;

namespace Gazebo.Simulator.Sequence.Basic
{
    public class PowerOnStartupTest : ISequence
    {
        private int instrPtr = 0;

        private byte[] ops = new byte[]
        {
            Ops.Descriptor, 0x04,
            Ops.Color, 0x00, 0xFF, 0x00,
            Ops.AllOn,
            Ops.Delay, 0x00, 0x10,
            Ops.Color, 0x00, 0x00, 0xFF,
            Ops.AllOn,
            Ops.Delay, 0x00, 0x10,
            Ops.Color, 0xFF, 0x00, 0x00,
            Ops.AllOn,
            Ops.Delay, 0x00, 0x010,
            Ops.Color, 0xFF, 0xFF, 0xFF,
            Ops.AllOn,
            Ops.Halt
        };

        public byte GetNextByte()
        {
            return ops[this.instrPtr++];
        }
    }
}
