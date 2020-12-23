package p1;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("请输入用户名：");
        String username = scanner.nextLine();

        if (username.equals("admin")){
            System.out.println("请输入密码：");
            String code = scanner.nextLine();

            if (!code.equals("12345")){
                System.out.println("密码错误！");
            }else {
                System.out.println("登录成功！欢迎" + username + "！");
            }
        }else {
            System.out.println("用户名错误！");
        }
    }
}
