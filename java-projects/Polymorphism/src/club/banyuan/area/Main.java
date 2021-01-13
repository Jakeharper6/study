package club.banyuan.area;
//改造AreaCalculator中的show方法，可以接收多个形状。
//扩展一个矩形类，同样提供计算周长和面积的方法，传入到AreaCalculator中的show方法中

public class Main {
    public static void main(String[] args) {
        AreaCalculator areaCalculator = new AreaCalculator();
        areaCalculator.show(new Circle(20));
        areaCalculator.show(new Rectangle(20, 15));
    }
}
