/*编写一个控制台应用程序，要求用户输入4个int值，并显示它 们的乘积。
提示：前面看到可以使用Convert.ToDouble()命令把用户在控 制台上输入的数转换为double类型；
类似地，从string类型转换为int类型 的命令是Convert.ToInt32()。*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace p3_5
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, b, c, d;
            Console.WriteLine("输入4个整数");
            Console.WriteLine("第一个数:");
            a = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("第二个数:");
            b = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("第三个数:");
            c = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("第四个数:");
            d = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("这四个数相乘的结果是："+$"{a * b * c * d}");

            Console.ReadKey();
        }
    }
    
}
