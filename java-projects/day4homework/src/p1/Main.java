package p1;


//根据以下数据编写员工类，并创建对象
//张三，月薪15000，id=1110
//李四，月薪17000，id=1111


public class Main {

    String name;
    int salary;
    String identity;

    public Main(String name, int salary, String identity) {
        this.name = name;
        this.salary = salary;
        this.identity = identity;
    }

    /**
     * 将员工的月薪涨幅指定百分比
     *
     * @param percent 传入一个百分比的值
     */
    public void raiseSalary(double percent) {
        
    }

    /**
     * 将员工的月薪降幅指定百分比
     *
     * @param percent 传入一个百分比的值
     */
    public void cutSalary(double percent) {

    }

    /**
     * 返回员工信息
     *
     * @return 张三，月薪：xxx, id:xxx
     */
    public String getInfo() {
        return "";
    }

    public static void main(String[] args) {
        Main m1 = new Main("张三",15000,"1110");
        Main m2 = new Main("李四",17000,"1111");

        System.out.println(m1.name + "," + "月薪" + m1.salary + ", id=" + m1.identity);
        System.out.println(m2.name + "," + "月薪" + m2.salary + ", id=" + m2.identity);
    }
}
