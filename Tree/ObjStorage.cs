using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Tree
{
    class ObjStorage
    {
        //public void ReadObjFromFile(string fileName, IObjState obj)
        //{
        //    FileStream file = new FileStream(fileName, FileMode.Open, FileAccess.Read);
        //    StreamReader reader = new StreamReader(file);
        //    string[] arr = reader.ReadToEnd().Split('\n');
        //    reader.Close();
        //    Dictionary<string, string> state = new Dictionary<string, string>();
        //    foreach (string item in arr)
        //    {
        //        if (item != "")
        //            state.Add(item.Split(' ')[0], item.Split(' ')[2]);
        //    }
        //    obj.WriteStateToObject(state);
        //}
        //
        //public void WriteObjToFile(string fileName, IObjState obj)
        //{
        //    fileName += obj.ObjId + ".txt";
        //    Dictionary<string, string> state = obj.ReadStateFromObj();
        //    string content = "";
        //    foreach (KeyValuePair<string, string> item in state)
        //    {
        //        content += item.Key + " : " + item.Value + "\r\n";
        //    }
        //    FileStream file = new FileStream(fileName, FileMode.OpenOrCreate, FileAccess.Write);
        //    StreamWriter writer = new StreamWriter(file);
        //    writer.Write(content);
        //    writer.Close();
        //}

    }
}
