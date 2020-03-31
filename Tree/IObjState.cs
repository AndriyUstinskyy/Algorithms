using System;
using System.Collections.Generic;
using System.Text;

namespace Tree
{
    interface IObjState
    {
        string ObjId { get; }
        IDictionary<string, string> ReadStateFromObj();
        void WriteStateToObject(IDictionary<string, string> objState);
    }
}
