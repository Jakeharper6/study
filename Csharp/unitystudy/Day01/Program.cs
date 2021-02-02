using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day01
{
    class Program
    {
        //        练习
        //在控制台中，录入枪的信息
        //请输入枪的名称：
        //请输入弹匣容量：
        //请输入当前弹匣内子弹数量：
        //请输入剩余子弹数量：

        static void Main(string[] args)
        {
            string strName;
            int intAmmor;
            int intTemp;
            int intRest;
            Console.WriteLine("请输入枪的名称：");
            strName = Console.ReadLine();
            Console.WriteLine("请输入弹匣容量：");
            intAmmor = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("请输入当前弹匣内子弹数量：");
            intTemp = Convert.ToInt32(Console.ReadLine());
            intRest = intAmmor - intTemp;

            Console.WriteLine("枪的名称：" + strName);
            Console.WriteLine("弹匣容量：：" + intAmmor);
            Console.WriteLine("当前弹匣内子弹数量：" + intTemp);
            Console.WriteLine("剩余子弹数量：" + intRest);
            Console.ReadKey();
        }
    }
}
