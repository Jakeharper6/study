package p2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("请输入一个数字：");
        int input = scanner.nextInt();

        if (input == 0){
            System.out.println("输入的是0");
        }else{
            if (input > 0){
                if (input % 2 == 0){
                    System.out.println(input + "是偶数");
                }else {
                    System.out.println(input + "是奇数");
                }
            }else {
                if (input % 2 == 0){
                    System.out.println(input + "是负偶数");
                }else {
                    System.out.println(input + "是负奇数");
                }
            }
        }

    }
}
