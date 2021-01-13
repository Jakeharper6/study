package club.banyuan.area;

public class Rectangle extends Shape{
    private final int length;
    private final int width;

    public String getShapeName() {
        return "矩形";
    }

    public Rectangle(int length, int width) {
        this.length = length;
        this.width = width;
    }

    public double area() {
        return length * width;
    }

    public double perimeter() {
        return 2 * (length + width);
    }
}
