package club.banyuan;
//编写一个名为Commission的类，它具有以下功能： 它继承Hourly类。 它有两个实例变量（继承的变量除外）：
//
//      该雇员的总销售额（类型为double），
//      该雇员的佣金率（佣金率数据类型为double表示百分比佣金，用于计算该员工的销售收入（0.2表示该员工的销售收入为20％的佣金））。
//      构造函数有6个参数：前5个参数与Hourly相同（姓名，地址，电话号码，社会保险号，小时工资率），第6个是员工的佣金率。
//      构造函数应使用前5个参数调用父类的构造函数，然后使用第6个参数来设置佣金率。

//提供方法：
//      public void addSales（double totalSales），它将参数添加到表示总销售额的实例变量中。
//      pay方法必须调用父类的pay方法来计算工时的工资，然后再加上销售佣金。 （请参阅Executive类中的pay方法。）
//      总销售额应设置为0（注意：不需要将工作小时数设置为0，为什么不设置？）。
//      toString方法需要调用父类的toString方法，然后将总销售额添加到该方法中

//要测试新增的类，请按如下所示更新Staff.java：
//      将数组的大小增加到8。将两个Commission的对象添加到staffList中，提供自定义的姓名，地址，电话号码和社会保险号。
//      让一名员工每小时赚取6.25美元和20％的佣金，另一名员工每小时赚取9.75美元和15％的佣金。
//      对于添加的第一位员工，将工作时间设为35，总销售额为$ 400；
//      对于添加的第二位员工，将小时数设为40，将销售额设为$ 950。

public class Commission extends Hourly {

    private double salesAmount;
    private double rate;

    public Commission(String eName, String eAddress, String ePhone, String socSecNumber, double rate) {
        super(eName, eAddress, ePhone, socSecNumber, rate);
    }

    public Commission(String eName, String eAddress, String ePhone, String socSecNumber, double rate, double rate1) {
        super(eName, eAddress, ePhone, socSecNumber, rate);
        this.rate = rate1;
    }

    public double getSalesAmount() {
        return salesAmount;
    }

    public void setSalesAmount(double salesAmount) {
        this.salesAmount = salesAmount;
    }

    public double getRate() {
        return rate;
    }

    public void setRate(double rate) {
        this.rate = rate;
    }

    @Override
    public String toString() {
        return super.toString() + "\n销售总额：" + salesAmount;
    }

    public void addSales(double totalSales) {
        salesAmount += totalSales;
    }

    @Override
    public double pay() {
        double pay = super.pay() + salesAmount * rate;
        salesAmount = 0;
        return pay;
    }
}
