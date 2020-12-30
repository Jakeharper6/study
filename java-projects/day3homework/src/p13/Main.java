package p13;

//圆形，圆心坐标(0,0)，半径15
//圆形，圆心坐标(10,12)，半径20
//三角形，三点坐标(1,2),(3,4),(5,6)
//三角形，三点坐标(1,1),(2,2),(3,3)

public class Main {
    public static void main(String[] args) {
        Point center1 = new Point(0,0);
        Circle c1 = new Circle(center1,15);

        Point center2 = new Point(10,12);
        Circle c2 = new Circle(center2,20);

        Point triangle1a = new Point(1,2);
        Point triangle1b = new Point(3,4);
        Point triangle1c = new Point(5,6);

        Triangle t1 = new Triangle(triangle1a,triangle1b,triangle1c);

        Point triangle2a = new Point(1,1);
        Point triangle2b = new Point(2,2);
        Point triangle2c = new Point(3,3);

        Triangle t2 = new Triangle(triangle2a,triangle2b,triangle2c);

        c1.printCircle();
        c2.printCircle();

        t1.printTriangle();
        t2.printTriangle();
    }
}
