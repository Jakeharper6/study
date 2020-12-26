package whiledemo;

// 找出1-100 能够整除9的数字
public class FindDiv {

    public static void main(String[] args) {

        // while(){}
        int a = 1;
        int divisor = 9;
        while (a < 101) {
            System.out.println(a + "是否可以整除" + divisor + "? " + (a % divisor == 0));
            a++;
        }

        // 除数
        // for
        // int divisor = 9;
        for (int i = 1; i < 101; i++) {
            System.out.println(i + "是否可以整除" + divisor + "? " + (i % divisor == 0));
        }

        // 统计有多少个数字可以被divisor整除

        int count = 0;
        for (int i = 1; i < 101; i++) {
            if (i % divisor == 0) {
                count++;
            }
        }
        System.out.println("1-100之间共有" + count + "个数字可以被" + divisor + "整除");
    }
}