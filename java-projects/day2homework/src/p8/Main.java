package p8;

//圆形，圆心坐标(0,0)，半径15
//圆形，圆心坐标(10,12)，半径20
//三角形，三点坐标(1,2),(3,4),(5,6)
//三角形，三点坐标(1,1),(2,2),(3,3)

public class Main {
    public static void main(String[] args) {
        Point center1 = new Point();
        center1.x = 0;
        center1.y = 0;
        Circle c1 = new Circle();
        c1.center = center1;
        c1.radius = 15;

        Point center2 = new Point();
        center2.x = 10;
        center2.y = 12;
        Circle c2 = new Circle();
        c2.center = center2;
        c2.radius = 20;

        Point triangle1a = new Point();
        triangle1a.x = 1;
        triangle1a.y = 2;

        Point triangle1b = new Point();
        triangle1b.x = 3;
        triangle1b.y = 4;

        Point triangle1c = new Point();
        triangle1c.x = 5;
        triangle1c.y = 6;

        Triangle t1 = new Triangle();
        t1.a = triangle1a;
        t1.b = triangle1b;
        t1.c = triangle1c;

        Point triangle2a = new Point();
        triangle2a.x = 1;
        triangle2a.y = 1;

        Point triangle2b = new Point();
        triangle2b.x = 2;
        triangle2b.y = 2;

        Point triangle2c = new Point();
        triangle2c.x = 3;
        triangle2c.y = 3;

        Triangle t2 = new Triangle();
        t2.a = triangle2a;
        t2.b = triangle2b;
        t2.c = triangle2c;

        System.out.println("圆形，圆心坐标(" + c1.center.x + "," + c1.center.y + "),半径" + c1.radius);
        System.out.println("圆形，圆心坐标(" + c2.center.x + "," + c2.center.y + "),半径" + c2.radius);

        System.out.println(
                "三角形，三点坐标" + "(" + t1.a.x + "," + t1.a.y + ")," + "(" + t1.b.x + "," + t1.b.y + ")," + "("
                        + t1.c.x + "," + t1.c.y + ")");

        System.out.println(
                "三角形，三点坐标" + "(" + t2.a.x + "," + t2.a.y + ")," + "(" + t2.b.x + "," + t2.b.y + ")," + "("
                        + t2.c.x + "," + t2.c.y + ")");
    }
}
