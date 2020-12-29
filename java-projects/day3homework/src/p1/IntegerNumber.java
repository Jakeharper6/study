package p1;

//创建两个IntegerNumber的对象，为两个对象integerNumber赋值
//        调用printNumber方法检查赋值结果是否正确
//        添加一个构造方法用来初始化integerNumber的值，修改main方法中代码保证运行通过。
//        integerNumber 是什么变量
//        成员变量(实例变量)
//        参数
//        局部变量
//        如果实例化 IntegerNumber 没有为integerNumber赋值，integerNumber的默认值是什么。

public class IntegerNumber {
    int integerNumber;

    public IntegerNumber(int integerNumber) {
        this.integerNumber = integerNumber;
    }

    public void printNumber() {
        System.out.println(integerNumber);
    }

    public static void main(String[] args) {
        IntegerNumber inte1 = new IntegerNumber(1);
        IntegerNumber inte2 = new IntegerNumber(2);

        inte1.printNumber();
        inte2.printNumber();
    }
}
