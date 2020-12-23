package p2;

//银行账号 9559980120193861412 银行：工商银行 户名:张三  余额：3000
//银行账号 9558804000137629461 银行：招商银行 户名:李四  余额：5000

import java.util.Scanner;

public class Account {
    Scanner scanner = new Scanner(System.in);

    /**
     * 向指定的账户转账指定的金额
     *
     * @param account 将钱转入的账号
     * @param amount  转入多少钱
     */
    public void transferTo(Account account, int amount) {

    }

    /**
     * 存钱
     *
     * @param amount 金额
     */
    public void deposit(int amount) {
    }

    /**
     * 取钱
     *
     * @param amount 金额
     */
    public void withdraw(int amount) {

    }

    public static void main(String[] args) {
        BankMember member1 = new BankMember();
        member1.number = "9559980120193861412";
        member1.bankname = "工商银行";
        member1.account = "张三";
        member1.balance = 3000;

        BankMember member2 = new BankMember();
        member2.number = "9558804000137629461";
        member2.bankname = "招商银行";
        member2.account = "李四";
        member2.balance = 5000;

        System.out.println("银行账号：" + member1.number + " 银行：" + member1.bankname + " 户名：" + member1.account + " 余额：" + member1.balance);
        System.out.println("银行账号：" + member2.number + " 银行：" + member2.bankname + " 户名：" + member2.account + " 余额：" + member2.balance);
    }
}
