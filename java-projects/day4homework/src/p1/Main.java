package p1;

import java.util.Scanner;

//根据以下数据编写员工类，并创建对象
//张三，月薪15000，id=1110
//李四，月薪17000，id=1111


public class Main {
    Scanner scanner = new Scanner(System.in);

    /**
     * 将员工的月薪涨幅指定百分比
     *
     * @param percent 传入一个百分比的值
     */
    public void raiseSalary(double percent) {
        System.out.println("请输入涨幅程度：");
        double raiseDegree = scanner.nextDouble();
        System.out.println(raiseDegree);
    }

    /**
     * 将员工的月薪降幅指定百分比
     *
     * @param percent 传入一个百分比的值
     */
    public void cutSalary(double percent) {
        System.out.println("请输入降幅程度：");
        double cutDegree = scanner.nextDouble();
        System.out.println(cutDegree);
    }

    /**
     * 返回员工信息
     *
     * @return 张三，月薪：xxx, id:xxx
     */
//    public String getInfo() {
//
//

    public static void main(String[] args) {
        Member myMember1 = new Member();
        myMember1.name = "张三";
        myMember1.salary = 15000;
        myMember1.identity = 1110;

        Member myMember2 = new Member();
        myMember2.name = "李四";
        myMember2.salary = 17000;
        myMember2.identity = 1111;

        System.out.println(myMember1.name + ",月薪" + myMember1.salary + ",id=" + myMember1.identity);
        System.out.println(myMember2.name + ",月薪" + myMember2.salary + ",id=" + myMember2.identity);
    }
}
