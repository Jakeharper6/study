package p13;

public class Triangle {
    Point a;
    Point b;
    Point c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public void printTriangle(){
        System.out.println(
                "三角形，三点坐标" + "(" + this.a.x + "," + this.a.y + ")," + "(" + this.b.x + "," + this.b.y + ")," + "("
                        + this.c.x + "," + this.c.y + ")");
    }
}
