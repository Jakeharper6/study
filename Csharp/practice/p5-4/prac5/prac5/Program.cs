using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace prac5
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Enter a string below:");
            string myString = ReadLine();
            myString = myString.Replace("no", "yes");

            Write($"Replaced \"no\" to \"yes\"\n{myString}");

            ReadKey();
        }
    }
}
