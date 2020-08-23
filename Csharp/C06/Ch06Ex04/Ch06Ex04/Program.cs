using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Ch06Ex04
{
    class Program
    {
        static string myString;
        static void Write()
        {
            string myString = "String defined in Write()";
            WriteLine("Now in Write()");
            WriteLine($"Local myString = {myString}");
            WriteLine($"Global myString = {Program.myString}");

        }

        static void Main(string[] args)
        {
            string myString = "String defined in Main()";
            Program.myString = "Global string";
            Write();
            WriteLine("\nNow in Main()");
            WriteLine($"Local myString = {myString}");
            WriteLine($"Global myString = {Program.myString}");

            ReadKey();
        }
    }
}
