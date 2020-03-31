using System;
using System.Collections.Generic;
using System.Text;

namespace Tree
{
    abstract class Node //вершина
    {
        private Node parent = null;
        protected List<Node> children = new List<Node>();
        private readonly string nodeType;
        public Node(string nodeType)
        {
            this.nodeType = nodeType;
        }
        public Node GetParent() //батьківська вершина
        {
            return parent;
        }

        public Node AddChild(Node child)  // додає сина
        {
            child.parent = this;
            children.Add(child);
            return this;
        }

        public void RemoveChild(int i)  // вилучає сина та всіх його синів
        {
            if (i >= 0 && i < children.Count)
            {
                children.RemoveAt(i);
            }
            else
            {
                Console.WriteLine("Element {0} is out of range", i);
            }
        }

        public Node GetChild(int i)  // повертає сина
        {
            return children[i];
        }

        public int ChildCount { get { return children.Count; } }  // кількість синів

        public string NodeType { get { return nodeType; } } //тип вузла

        public int CalcLevel()
        {
            int level = 1;
            Node p = parent;
            while (p != null)
            {
                p = p.parent;
                level++;
            }
            return level;
        }
        public abstract void Print();  // виводить вузел та піддерево на консоль в JSON форматі 
    }

    class Department : Node  //може мати тип університет, інститут, факультет, група або кафедра
    {
        public Department(string NodeType,string DepartmentName) : base(NodeType)
        {
            this.DepartmentName = DepartmentName;
        }

        public string DepartmentName { get; set; }

        public override void Print()
        {
            int level = CalcLevel();
            string tabs = new String('\t', level + 1);
            Console.Write(tabs);
            Console.Write($"{level}) ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ DepartmentName}\n");
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write(tabs);
            Console.Write("Nazva : ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ NodeType} \n");
            Console.ForegroundColor = ConsoleColor.Gray;


            foreach (var item in children)
            {
                item.Print();
            }
        }

    }

    abstract class Person: Node  //самостійно не використовується  
    {
        private readonly string nodeType = null;
        public Person(string PersonName , string nodeType) : base(nodeType)
        {
            this.PersonName = PersonName;
            this.nodeType = nodeType;
        }

        public string PersonName { get; set; }
        public override void Print()
        {
            int level = CalcLevel();
            string tabs = new String('\t', level + 1);
            Console.Write(tabs);
            Console.Write($"{level})");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{nodeType}\n");
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write(tabs);
            Console.Write($"Nazva obektu:");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ PersonName}");
            Console.ForegroundColor = ConsoleColor.Gray;

        }

    }

    class Student: Person //типи: студент  
    {
        public Student(string personName,string nodeType , int course): base(personName,nodeType)
        {
            Course = course;
        }

        float AvgScore { get { return 0; }}
        int Course { get; set; }
        public override void Print()
        {
            base.Print();
            int level = CalcLevel();
            string tabs = new String('\t', level + 1);
            Console.Write(tabs);
            Console.Write("Kurs: ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ Course}\n");
            Console.ForegroundColor = ConsoleColor.Gray;
            foreach (var item in children)
            {
                item.Print();
            }
        }

    }

    class Teacher: Person  //типи: асистент, доцент, професор, завідувач  
    {
        public Teacher(string personName , string TeacherSubject, string nodeType, string degree ) : base(personName, nodeType)
        {
            this.TeacherSubject = TeacherSubject;
            AcademicDegree = degree;
        }
        public string TeacherSubject { get; set; }
        public string AcademicDegree { get; set; }
        public override void Print()
        {
            base.Print();
            int level = CalcLevel();
            string tabs = new String('\t', level + 1);
            Console.Write(tabs);
            Console.Write("Prydmet vykladacha : ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($" {TeacherSubject}");
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write(tabs);

            Console.Write("Vchenyy stupin:");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ AcademicDegree}\n\n");
            Console.ForegroundColor = ConsoleColor.Gray;
            
        }
    }

    abstract class SubjectBase: Node  //самостійно не використовується   
    {
        public SubjectBase(string nodeType) : base(nodeType)
        {
            SubjectName = nodeType;
        }
        string SubjectName { get; set; }
        public override void Print()
        {
            int level = CalcLevel();
            string tabs = new String('\t', level + 1);
            Console.Write(tabs);
            Console.Write($"{level})");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ SubjectName}\n");
            Console.ForegroundColor = ConsoleColor.Gray;

        }

    }

    class Subject: SubjectBase  //тип: предмет
    {
        public Subject(string nodeType, string name, int lectureHours, int practicaHours) : base(nodeType)
        {
            SubjectName = name;
            LectureHours = lectureHours;
            PracticaHours = practicaHours;
        }
        string SubjectName { get; set; }
        int LectureHours { get; set; }
        int PracticaHours { get; set; }
        
        public override void Print()
        {
            base.Print();
            int level = CalcLevel();
            string tabs = new String('\t', level + 1);
            Console.Write(tabs);
            Console.Write($"Nazva dyscypliny: ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ SubjectName}\n");
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write(tabs);
            Console.Write($"Godyn lekciy: ");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine($"{ LectureHours}\n");
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write(tabs);
            Console.Write($"Godyn praktyk: ");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine($"{ PracticaHours}\n");
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write(tabs);
            Console.Write($"Vsogo godyn: ");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine( $"{ LectureHours + PracticaHours}\n\n");
            Console.ForegroundColor = ConsoleColor.Gray;

        }
    }

    class Exam : SubjectBase  //тип: екзамен
    {
        public Exam(string nodeType,string ExamSubject, int scores) : base(nodeType)
        {
            Scores = scores;
            this.ExamSubject = ExamSubject;
        }
        public string ExamSubject;
        public int Scores { get; set; }
        public override void Print()
        {
            base.Print();
            int level = CalcLevel();
            string tabs = new String('\t', level + 1);
            Console.Write(tabs);
            Console.Write("Nazva examenu : ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ExamSubject}");
            Console.ForegroundColor = ConsoleColor.Gray;

            Console.Write(tabs);


            Console.Write($"Nabranu baliv za ekzamyn: ");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ Scores}\n\n");
            Console.ForegroundColor = ConsoleColor.Gray;

        }
    }

    class UnivTree
    {
        public Node univ;

        public void PrintFormatted()  // виводить дерево на екран в JSON форматі
        {
            univ.Print();
        }
    }
}
