package CakePrac;

//基于Cake类和下表，定义两个子类，OrderCake和ReadyMadeCake。
//
//              OrderCake	ReadyMadeCake
//属性	        weightInKG	quantity
//价格计算方法	price*weight	price*quantity
//
// 通过使用定义的类，编写一个应用程序，它将：
//
//声明一个由10个Cake对象组成的数组；
//输入Cake对象的数据并将其存储到数组中，奇数下标存放OrderCake，偶数下标存放ReadyMadeCake；
//显示所有蛋糕的总价；
//显示ReadyMadeCake蛋糕的总价和数量之和；
//显示最高价格出售的蛋糕的信息,显示蛋糕是按斤卖还是按数量卖。

import java.util.Random;

public class Main {
    public static void main(String[] args) {

        Cake[] cakes = new Cake[10];

        Random random = new Random();

        for (int i = 0; i < cakes.length; i++) {
            if (i % 2 == 0){
                cakes[i] = new ReadyMadeCake(random.nextInt(10) + 1,random.nextDouble() * 10);
            }else {
                cakes[i] = new OrderCake(random.nextInt(10) + 1,random.nextDouble() * 10);
            }
        }

        double totalPrice = 0.0;
        int totalQuantity = 0;

        for (int i = 0; i < cakes.length; i++) {
            totalPrice += cakes[i].price();
        }
        System.out.println(totalPrice);

        for (int i = 0; i < cakes.length; i++) {
            if (i % 2 == 0){
                totalQuantity += ((ReadyMadeCake)cakes[i]).getQuantity();
            }
        }
        System.out.println(totalQuantity);
    }
}
