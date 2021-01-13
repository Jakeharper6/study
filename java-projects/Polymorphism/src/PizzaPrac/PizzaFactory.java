package PizzaPrac;

import java.util.Scanner;

public class PizzaFactory {
    public static Pizza getPizza(int num){
        Pizza pizza = null;
        Scanner scanner = new Scanner(System.in);
        if (num == 1){
            System.out.println("请入培根克数：");
            int grams = scanner.nextInt();
            System.out.println("请输入比萨大小：");
            int size = scanner.nextInt();
            System.out.println("请输入比萨价格：");
            int price = scanner.nextInt();
            pizza = new BaconPizza("培根比萨",price,size,grams);
        }
        if (num == 2){
            System.out.println("请入配料信息：");
            String ingredients = scanner.next();
            System.out.println("请输入比萨大小：");
            int size = scanner.nextInt();
            System.out.println("请输入比萨价格：");
            int price = scanner.nextInt();
            pizza = new SeafoodPizza("海鲜比萨",price,size,ingredients);
        }

        return pizza;
    }
}
