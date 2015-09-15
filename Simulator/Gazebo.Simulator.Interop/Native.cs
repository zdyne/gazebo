using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Gazebo.Simulator.Interop
{
    public class Native
    {
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate byte GetNextOpFn();

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int SetLedFn(int led, byte r, byte g, byte b);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void LatchLedsFn();

        [DllImport("Gazebo.Core.Engine.dll", CallingConvention=CallingConvention.Cdecl, EntryPoint="gz_engine_init")]
        public static extern int GzEngineInit(
            [MarshalAs(UnmanagedType.FunctionPtr)]GetNextOpFn getNextOp,
            [MarshalAs(UnmanagedType.FunctionPtr)]SetLedFn setLed,
            [MarshalAs(UnmanagedType.FunctionPtr)]LatchLedsFn latchLeds);

        [DllImport("Gazebo.Core.Engine.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "gz_engine_run")]
        public static extern int GzEngineRun();
    }
}
