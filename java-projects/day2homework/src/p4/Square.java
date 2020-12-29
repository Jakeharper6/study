package p4;

//创建一个 Square类
//        类内部包含一个整数类型的side成员变量
//        一个SIDES_NUMBER的成员常量为4
//        创建一个SquareTest的类
//        包含一个main方法，用来实例化Square类，并且为side赋
//        向控制台输出side和SIDES_NUMBER的值，如下
//
//        正方形4个边的边长5
//        正方形4个边的边长10

public class Square {

    public static void main(String[] args) {
        SquareDetail s1 = new SquareDetail();
        s1.side = 5;

        SquareDetail s2 = new SquareDetail();
        s2.side = 10;

        System.out.println("正方形" + s1.SIDES_NUMBER + "个边的边长" + s1.side);
        System.out.println("正方形" + s2.SIDES_NUMBER + "个边的边长" + s2.side);
    }
}
