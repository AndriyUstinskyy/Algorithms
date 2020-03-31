using System;
using System.Collections.Generic;
using System.Text;

namespace Tree
{
    class Book: IObjState
    {
        public string Title{ get; set; }
        public string Author { get; set; }
        public int PagesCnt { get; set; }

        public Book(string title, string author, int pagesCnt)
        {
            this.Title = title;
            this.Author = author;
            this.PagesCnt = pagesCnt;
        }

        public Book(IDictionary<string, string> state)
        {
            WriteStateToObject(state);
        }

        public string ObjId{get{ return Title;}}

        public IDictionary<string, string> ReadStateFromObj()
        {
            IDictionary<string, string> state = new Dictionary<string, string>();
            state.Add("Title", Title);
            state.Add("Author", Author);
            state.Add("PagesCnt", Convert.ToString(PagesCnt));
            return state;

        }

        public void WriteStateToObject(IDictionary<string, string> objState)
        {
            Title = objState["Title"];
            Author = objState["Author"];
            PagesCnt = Convert.ToInt32(objState["PagesCnt"]);
        }

    }
}
