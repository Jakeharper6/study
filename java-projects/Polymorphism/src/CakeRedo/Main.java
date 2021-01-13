package CakeRedo;

////基于Cake类和下表，定义两个子类，OrderCake和ReadyMadeCake。
////
////              OrderCake	ReadyMadeCake
////属性	        weightInKG	quantity
////价格计算方法	price*weight	price*quantity
////
//// 通过使用定义的类，编写一个应用程序，它将：
////
////声明一个由10个Cake对象组成的数组；
////输入Cake对象的数据并将其存储到数组中，奇数下标存放OrderCake，偶数下标存放ReadyMadeCake；
////显示所有蛋糕的总价；
////显示ReadyMadeCake蛋糕的总价和数量之和；
////显示最高价格出售的蛋糕的信息,显示蛋糕是按斤卖还是按数量卖。

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();

        Cake[] cakes = new Cake[10];

        for (int i = 0; i < cakes.length; i++) {
            if (i % 2 == 0){
                cakes[i] = new ReadyMadeCake(rand.nextInt(10) + 1,rand.nextDouble() * 10);
            }else {
                cakes[i] = new OrderCake(rand.nextInt(10) + 1,rand.nextDouble() * 10);
            }
            System.out.println(cakes[i].calPrice());
        }

        double totalprice = 0;
        double readyPrice = 0;
        int readyQuantity = 0;
        for (int i = 0; i < cakes.length; i++) {
            totalprice += cakes[i].calPrice();
            if (i % 2 == 0){
                readyPrice += cakes[i].calPrice();
                readyQuantity += ((ReadyMadeCake)cakes[i]).getQuantity();
            }
        }
        System.out.println("总价：" + totalprice);
        System.out.println("ReadyMadeCake蛋糕的总价:" + readyPrice);
        System.out.println("ReadyMadeCake蛋糕数量之和:" + readyQuantity);

        double temp = 0;
        int subscript = 0;
        String judge;
        for (int i = 0; i < cakes.length; i++) {
            if (temp < cakes[i].calPrice()){
                temp = cakes[i].calPrice();
                subscript = i;
            }
        }
        if (subscript % 2 == 0){
            judge = "按数量卖了";
        }else {
            judge = "按斤卖了";
        }

        System.out.println("最高价格出售的蛋糕卖了" + cakes[subscript].calPrice() + "元");
        System.out.print(judge);
        cakes[subscript].amount();
    }
}
