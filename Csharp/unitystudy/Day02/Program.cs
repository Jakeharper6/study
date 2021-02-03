using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day02
{
    //练习：让用户在控制台中录入2个数,1个运算符
    //很据运算符计算2个数字
    //"请输入第一个数字："
    //"请输入第二个数字："
    //"请输入运算符："
    //"运算符输入有误"

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("在控制台中录入2个数,1个运算符");
            Console.WriteLine("第一个:");
            int firstNum = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("第二个:");
            int secondNum = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("运算符:");
            string method = Console.ReadLine();
            int result = 0;
            if (method == "+")
            {
                result = firstNum + secondNum;
                Console.WriteLine($"运算结果为:{result}");
            }
            else if (method == "-")
            {
                result = firstNum - secondNum;
                Console.WriteLine($"运算结果为:{result}");
            }
            else if (method == "*")
            {
                result = firstNum * secondNum;
                Console.WriteLine($"运算结果为:{result}");
            }
            else if (method == "/")
            {
                result = firstNum / secondNum;
                Console.WriteLine($"运算结果为:{result}");
            }
            else
            {
                Console.WriteLine("运算符输入有误");
            }

            
            Console.ReadKey();
        }
    }
}
