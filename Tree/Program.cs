using System;

namespace Tree
{
    class Program
    {
        static void Main(string[] args)
        {
            UnivTree univ = new UnivTree();
            Department dep = new Department("KNU", "Universytet");
            univ.univ = dep;

            Department fit = new Department("FIT", "Facultet");
            dep.AddChild(fit);

            Department ipz = new Department("IPZ", "Kafedra");
            fit.AddChild(ipz);

            Student vasya = new Student("Vasya", "Student", 3);
            ipz.AddChild(vasya);
            vasya.AddChild(new Subject("Dyscyplina", "OOP", 50, 60));

            Student petya = new Student("Petya", "Student", 1);
            ipz.AddChild(petya);

            petya.AddChild(new Exam("Examen" ,"Vyshcha matematyka", 89));

            ipz.AddChild(new Teacher("Olga Petrivna" , "Dyskretna Matematyca", "Vykladach", "Docent"));
            ipz.AddChild(new Teacher("Popereshnyak Svitlana" , "OPI", "Vykladach", "Docent"));

            fit.AddChild(new Department("KN", "Kafedra"));
            fit.AddChild(new Department("PP", "Kafedra"));

            Department lingv = new Department("IF", "Instytut");
            dep.AddChild(lingv);
            lingv.AddChild(new Department("KRF", "Kafedra"));
            lingv.AddChild(new Department("KEL", "Kafedra"));
            lingv.AddChild(new Department("KAFiP", "Kafedra"));

            univ.PrintFormatted();

            UnivTree univ2 = new UnivTree();
            Department depkpi = new Department("KPI", "Universytet");
            univ2.univ = depkpi;

            univ2.PrintFormatted();
            
            Console.ReadKey();
        }
    }
    
}
