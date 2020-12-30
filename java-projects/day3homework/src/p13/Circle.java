package p13;

public class Circle {
    Point center;
    int radius;

    public Circle(Point center, int radius) {
        this.center = center;
        this.radius = radius;
    }

    public void printCircle(){
        System.out.println("圆形，圆心坐标(" + this.center.x + "," + this.center.y + "),半径" + this.radius);
    }
}
