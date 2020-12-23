package p3;

import java.util.Random;

public class random {
    public static void main(String[] args) {
        Random rand = new Random();
        int x = 101;
        int number = rand.nextInt(x) + 1;
        System.out.println(number);

        if (number >= 1 && number <= 5){
            System.out.println("大吉");
        }else if (number > 5 && number <= 15){
            System.out.println("中吉");
        }else if (number > 15 && number <= 30 ){
            System.out.println("小吉");
        }else if (number > 30 && number <= 60 ){
            System.out.println("吉");
        }else if (number > 60 && number <= 80 ){
            System.out.println("末吉");
        }else if (number > 80 && number <= 95 ){
            System.out.println("凶");
        }else if (number > 95 && number <= 100 ){
            System.out.println("大凶");
        }
    }
}
