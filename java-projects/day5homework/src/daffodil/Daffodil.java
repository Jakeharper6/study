package daffodil;

public class Daffodil {

    public static void main(String[] args) {

        int num = 1234;
        int position = 0;

        while (num > 0){
            int posNum = num % 10;
            num = num / 10;
            position++;
            System.out.println("第" + position + "位置是" + posNum);
        }
    }
}
