using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace p4_4
{
    class Program
    {
        static void Main(string[] args)
        {
            double numa;
            double numb;

            do
            {
                WriteLine("Enter two numbers below:");
                
                WriteLine("First number:");
                numa = ToDouble(ReadLine());
                WriteLine("");

                WriteLine("Second number:");
                numb = ToDouble(ReadLine());
                WriteLine("");

                if (numa > 10 && numb > 10)
                    WriteLine("Both of the numbers are more than 10.");
            } while (numa > 10 && numb > 10);

            WriteLine($"Your entering numbers are {numa} and {numb}");

            ReadKey();
        }
    }
}
