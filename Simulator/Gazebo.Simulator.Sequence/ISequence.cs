using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gazebo.Simulator.Sequence
{
    public interface ISequence
    {
        byte GetNextByte();
    }
}
