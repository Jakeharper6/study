package p1;

import java.sql.Array;
import java.util.Scanner;

//编写一个程序，接收用户的输入，用户只允许输入1~100之间的数字，输入0则表示结束输入。
//使用一个长度为100的数组统计用户输入的每个数字的数量，在用户输入0后显示。例如
//请输入数字：
//1
//20
//30
//15
//15
//2
//1
//30
//30
//0
//=====结果=====
//1输入了2次
//2输入了1次
//3输入了1次
//15输入了2次
//20输入了1次
//30输入了3次
//使用数组下标存放对应数字的输入次数，数组默认所有元素起始值为0，用户每输入一个数字，将数字对应的下标位置的数组元素值+1，最后输出所有元素不为0的数组，即为结果

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] rlt = new int[100];
        System.out.println("请输入数字：");
        String input = scanner.nextLine();

        while (!"0".equals(input)){
            int num = Integer.parseInt(input);
            if (num < 1 || num > 100){
                System.out.println("输入1~100之间的数字");
                input = scanner.nextLine();
                continue;
            }
            rlt[num -1] += 1;
            input = scanner.nextLine();
        }

        for (int i = 0; i < rlt.length; i++) {
            if (rlt[i] > 0){
                System.out.println(i + 1 + "输入了" + rlt[i] + "次");
            }
        }

    }
}
