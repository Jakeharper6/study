package scanner;

public class Square {
    int side;

    public Square(int side){
        this.side = side;
    }

    public int minus(Square square){
        return side * side - square.side * square.side;
    }

    public int add(Square square){
        return side * side + square.side * square.side;
    }

    public static void main(String[] args) {
        Square s1 = new Square(15);
        Square s2 = new Square(20);

        System.out.println("正方形面积之差是：" + s1.minus(s2));
        System.out.println("正方形面积之和是：" + s1.add(s2));
    }
}
