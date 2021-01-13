# JAVA与C#的区别

Java和C#都是编程的语言，它们是两个不同方向的两种语言

相同点:

他们都是面向对象的语言,也就是说,它们都能实现面向对象的思想(封装,继承,多态)

区别：

1.c#中的命名空间是namespace类似于Java中的package（包），在Java中导入包用import而c#中用using。
2.c#和Java都是从main函数入口的，但是c#中的main函数的首字母必须大写，它有四种写法如下：
static void Main(string args[]){}
static int Main(string args[]){}
static void Main(){}
static void Main(){}
而Java中只有一种形式：static void main(String [] args){}
3．数据类型：Java跟c#基本都差不多，但是Java的String类型的首字母必须大写，而c#中可以小写也可以大写，还有布尔型，Java中是boolean，c#中是bool。
4．变量的命名：Java中可以用$符号，而c#中不可以使用。
5．注释：Java比c#少一种"///"的文档注释。
6．输出：c#有三种方式输出：Cosole.WriteLine(); Cosole.WriteLine(要输出的值); Cosole.WriteLine("格式字符串"，变量列表); 前两种的用法与Java中的ystem.out.println()方法的用法相同，第三种方式是根据占位符输出的，比Java更方便了。
7．控制流语句：c#跟Java类似,还有c#中的switch如果case后面有内容必须要有break;Java可以没有break；
8．数组：两种语言的声明都是用new关键字的。都可以在创建数组的同时初始化如：int a[]={1,2,3,5,5};但是c#比Java多两种初始化如：int a[]=new int[3]{1,2,3}; int a[]=new int[]{1,2,3};
9．方法中传递的参数：两种语言都使用值传递与引用传递。
C#的引用传递的关键字是ref与out，ref侧重于修改，out侧重于输出。而Java中都以传值方式;
10．访问修饰符：C#中的访问修饰符与Java中的基本对应，但多出了一个internal。简而言之，C#有5种类型的可访问性，如下所示：
public：成员可以从任何代码访问。 protected：成员只能从派生类访问。
internal：成员只能从同一程序集的内部访问。
protected：成员只能从同一程序集内的派生类访问。
private：成员只能在当前类的内部访问。
11．由于C#中不存在final关键词，如果想要某个类不再被派生，你可以使用sealed关键词密封。
12．集合：两种语言都有集合ArrayList，还有通过键访问值的Java中是HashMap而c#中是HashTable。c#比Java多泛型集合List<T>与Dictionary<K,V>更容易了，无需拆箱装箱了，更安全了。
13．继承：Java中用关键字extends，c#只用"："就行了.调用父类的构造方法Java用super关键字，而c#用base关键字。
14．多态：抽象类和抽象方法两种语言都用abstract关键字。Java中另外一个类如果继承了它，实现直接重写此方法就可以了；而c#必须加上关键字override实现。C#还比Java多一种虚方法来实现多态。
15．接口：都用关键字interface定义，Java实现用关键字implements；c#用"："实现。在C#中，接口内的所有方法默认都是公用方法。在Java中，方法声明可以带有public修饰符（即使这并非必要），但在C#中，显式为接口的方法指定public修饰符是非法的。
16．C#中的is操作符与Java中的instanceof操作符一样，两者都可以用来测试某个对象的实例是否属于特定的类型。在Java中没有与C#中的as操作符等价的操作符。as操作符与is操作符非常相似，但它更富有"进取心"：如果类型正确的话，as操作符会尝试把被测试的对象引用转换成目标类型；否则，它把变量引用设置成null。
17．枚举器即enum类型(java无),把它作为一个变量值的类型使用，从而把变量可能的取值范围限制为枚举器中出现的值。
18．结构（Struct）与类很相似,而结构是一种值类型，它存储在栈中或者是嵌入式的,结构可以实现接口，可以象类一样拥有成员，但结构不支持继承。
19．c#保留了指针。Unsafe。(C#使用指针不安全,最后这条有待考证)