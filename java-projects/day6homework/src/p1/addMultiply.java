package p1;

import java.util.Scanner;

public class addMultiply {

    static int multiply(int n1, int n2){
            int j = 0;
            if (n1 == 0 || n2 == 0) {
                return 0;
            }else if (n2 == 1) {
                return n1;
            }else if (n1 == 1) {
                return n2;
            }else {
                for (int i = 0; i < n1; i++) {
                    j += n2;
                }
                return j;
            }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("输入两个数：");
        System.out.println("第一个数：");
        int a = scanner.nextInt();
        System.out.println("第二个数：");
        int b = scanner.nextInt();

        System.out.println("两数之积是：" + multiply(a, b));
    }
}
