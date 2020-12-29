package p7;

//编写一个Sum类，有两个int类型的成员变量。
//创建一个sum的实例方法，方法返回 两个变量的和。
//创建main方法测试sum的计算结果是否正确。

public class Sum {
    int a;
    int b;

    public int Sum(int a, int b) {
        this.a = a;
        this.b = b;
        return  this.a + this.b;
    }

    public static void main(String[] args) {
        Sum add = new Sum();
        System.out.println(add.Sum(1,2));
    }
}
