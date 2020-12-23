package scanner;

import java.util.Scanner;

public class circle {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //输入圆心x
        //输入圆心y
        //输入半径
        //输出圆心(x,y),半径

        System.out.println("输入圆心坐标x：");
        String x = scanner.nextLine();

        System.out.println("输入圆心坐标y：");
        String y = scanner.nextLine();

        System.out.println("输入圆心半径：");
        String radius = scanner.nextLine();

        System.out.println("圆心坐标(" + x + "," + y + ")," + "半径：" + radius);
    }
}
