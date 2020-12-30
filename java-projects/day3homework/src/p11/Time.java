package p11;

public class Time {
    int hour;
    int minute;
    int second;

    public Time(int hour, int minute, int second){
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public void printDetail(){
        System.out.printf("%02d:%02d:%02d", this.hour, this.minute, this.second);
    }

    public static void main(String[] args) {
        Time t1 = new Time(15,0,0);

        Time t2 = new Time(0,0,0);

        Time t3 = new Time(2,0,0);

        t1.printDetail();
        System.out.println();
        t2.printDetail();
        System.out.println();
        t3.printDetail();
        System.out.println();
    }
}
