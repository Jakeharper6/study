package p10;

public class Circle {
    String color;
    double radius;
    final String UNIT = "CM";

    public Circle(String color, double radius) {
        this.color = color;
        this.radius = radius;
    }

    public void printDetail(){
        System.out.println(this.color + "的圆形,半径是" + this.radius + UNIT);
    }

    public static void main(String[] args) {
        Circle c1 = new Circle("黄色",1.5);

        Circle c2 = new Circle("红色",2.2);

        Circle c3 = new Circle("蓝色",3.0);

        System.out.println();
        c1.printDetail();
        c2.printDetail();
        c3.printDetail();
    }
}
