 using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace prac6
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Enter a string:");
            string myString = ReadLine();
            myString = "\"" + myString.Replace(" ", "\" \"") + "\"";
            WriteLine($"Added double quotes around words:{myString}");

            ReadKey();
        }
    }
}
