package p9;

//创建一个 Square类
//        类内部包含一个整数类型的side成员变量
//        一个SIDES_NUMBER的成员常量为4
//        创建一个SquareTest的类
//        包含一个main方法，用来实例化Square类，并且为side赋
//        向控制台输出side和SIDES_NUMBER的值，如下
//
//        正方形4个边的边长5
//        正方形4个边的边长10

//使用构造方法简化初始化的操作。增加实例方法printDetail() 打印信息。

public class Square {
    final int SIDES_NUMBER = 4;
    int side;

    public Square(int side) {
        this.side = side;
    }

    public void printDetail(){
        System.out.println("正方形" + SIDES_NUMBER + "个边的边长" + this.side);
    }
    public static void main(String[] args) {
        Square s1 = new Square(5);
        Square s2 = new Square(10);

        s1.printDetail();
        s2.printDetail();
    }
}
