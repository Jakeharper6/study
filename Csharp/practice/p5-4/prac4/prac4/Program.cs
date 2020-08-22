using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace prac4
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Enter a string below:");
            string myString = ReadLine();
            char[] myChar = myString.ToCharArray();
            
            int myLength = myChar.Length;
            char[] bakeChar = new char[myLength];
            
            for (int i = 0; i < myLength; i++)
            {
                bakeChar[i] = myChar[myLength - 1 - i];
            }
            
            foreach (char word in bakeChar)
            {
                Write($"{word}");
            }

            ReadKey();
        }
    }
}
