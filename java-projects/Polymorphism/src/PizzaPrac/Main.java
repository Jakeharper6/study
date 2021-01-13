package PizzaPrac;
//编写程序实现比萨制作。需求说明编写程序，接收用户输入的信息，选择需要制作的比萨。
// 可供选择的比萨有：培根比萨和海鲜比萨。
//实现思路及关键代码
//1)分析培根比萨和海鲜比萨
//2)定义比萨类
//  a)属性：名称、价格、大小
//  b)方法：展示
//3)定义培根比萨和海鲜比萨继承自比萨类
//4)定义比萨工厂类，根据输入信息产生具体的比萨对象

//请选择想要制作的比萨(1。培根比萨2。海鲜比萨):1
//请入培根克数：
//25
//请输入比萨大小:12
//请输入比萨价格:105
//名称：培根根萨
//价格:105元
//大小；12寸
//培根克数:25

//请选择想要易作的比萨(1，培根比萨2。海鲜比萨):2
//请入配料信息：
//配料：虾仁、鱿鱼卷，墨鱼
//请输入比萨大小:10
//请输入比萨价格:78
//名称：海鲜披萨
//价格:78元
//大小:10寸

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请选择想要制作的比萨(1。培根比萨2。海鲜比萨):");
        int num = scanner.nextInt();

        Pizza p = PizzaFactory.getPizza(num);
        System.out.println(p.show());
    }
}
