package p3;

//定义长方形的类
//
//        定义长度成员变量，数据类型为int
//
//        定义宽度成员变量，数据类型为int
//
//        定义main方法，创建三个对象，分别赋值如上数据，然后打印三个对象的数据到控制台
//
//        长方形的长：5，宽：3
//        长方形的长：10，宽：0
//        长方形的长：300，宽：120

public class Rectangle {
    int length;
    int width;

    public Rectangle(int length, int width) {
        this.length = length;
        this.width = width;
    }

    public void print(){
        System.out.println("长方形的长：" + this.length + "，宽：" + this.width);

    }

    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(5,3);
        Rectangle r2 = new Rectangle(10,0);
        Rectangle r3 = new Rectangle(300,120);

        r1.print();
        r2.print();
        r3.print();
    }
}
