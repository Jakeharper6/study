package p4;

import java.util.Scanner;
import java.util.Random;

public class game {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random rand = new Random();

        System.out.println("猜拳");
        System.out.println("1：石头");
        System.out.println("2：剪刀");
        System.out.println("3：布");
        System.out.println("你的输入：");

        int input;
        do {
            input = scanner.nextInt();
            System.out.println("请输入1-3的数！");
        }while (input < 1 || input > 3);

        int comp = rand.nextInt(3) + 1;

        switch (comp){
            case 1:
                System.out.println("电脑出的是——石头");
                break;
            case 2:
                System.out.println("电脑出的是——剪刀");
                break;
            case 3:
                System.out.println("电脑出的是——布");
                break;
        }

        switch (input){
            case 1:
                System.out.println("你出的是——石头");
                break;
            case 2:
                System.out.println("你出的是——剪刀");
                break;
            case 3:
                System.out.println("你出的是——布");
                break;
        }

        if (input == comp){
            System.out.println("平局");
        }else if (input == 1){
            if (comp == 2){
                System.out.println("你赢了");
            }else {
                System.out.println("你输了");
            }
        }else if (input == 2){
            if (comp == 3){
                System.out.println("你赢了");
            }else {
                System.out.println("你输了");
            }
        }else if (input == 3){
            if (comp == 1){
                System.out.println("你赢了");
            }else {
                System.out.println("你输了");
            }
        }
    }
}
