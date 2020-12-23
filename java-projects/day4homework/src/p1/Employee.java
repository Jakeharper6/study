package p1;

public class Employee {

    // 张三，月薪15000，id=1110
    // 李四，月薪17000，id=1111

    String name;
    int salary;
    String id;

    public Employee() {
    }

    public Employee(String name, int salary, String id) {
        this.name = name;
        this.salary = salary;
        this.id = id;
    }

    public static void main(String[] args) {
        Employee e1 = new Employee();
        e1.name = "张三";
        e1.salary = 15000;
        e1.id = "1110";

        // e1.salary * 0.1  int * double 结果是double
        // e1.salary + (double)  int + double 结果是double
        // e1.salary = double 赋值不允许，因为数据类型不一致
        // e1.salary = (int)表达式结果  进行强制类型转换，小数部分丢弃掉
        // e1.salary = e1.salary + e1.salary * 0.1;
        e1.salary = (int) (e1.salary + e1.salary * 0.1);
        System.out.println(e1.salary);

        // e1.涨工资(百分之10);

        Employee e2 = new Employee("李四", 17000, "1111");
        System.out.println("涨工资之前");
        System.out.println(e2.getInfo());
        e2.raiseSalary(0.2);
        System.out.println("涨工资之后");
        System.out.println(e2.getInfo());

        e2.cutSalary(0.2);
        System.out.println(e2.getInfo());

    }

    /**
     * 将员工的月薪涨幅指定百分比
     *
     * @param percent 传入一个百分比的值
     */
    public void raiseSalary(double percent) {
        // e1.salary = (int) (e1.salary + e1.salary * 0.1);
        int raise = (int) (salary * percent);
        salary = (int) (salary + salary * percent);
        System.out.println("庆祝" + name + "涨了工资" + raise);
    }

    /**
     * 将员工的月薪降幅指定百分比
     *
     * @param percent 传入一个百分比的值
     */
    public void cutSalary(double percent) {
        salary = (int) (salary - salary * percent);
        // 实例方法可以调用类中定义的其他的实例方法
        // 方法会隐式的传递调用方法的对象到后面的实例方法中
        // raiseSalary(-percent);
    }

    /**
     * 返回员工信息
     *
     * @return 张三，月薪：xxx, id:xxx
     */
    public String getInfo() {
        return name + ",月薪：" + salary + ",id:" + id;
    }
}
