# C#入门经典

### OOP语言

#### 第3章

1. **W**rite**L**ine等语法大小写

2. using **static** System. Console(/Convert...);

   **ToInt32()**和**ToDouble()**方法是 System. Convert静态类的一部分

3. 用于在程序结束前等待用户输入内容： Console**.ReadKey()**;

4. **非整型变量赋值要加上后缀，如果不加默认为double。**例：float num = 0.1f;

5. **浮点型运算会出现舍入误差，可以用decimal代替。**例：decimal num = 0.1m；

   

#### 第4章

1. bool < name >  = < ... >; 	bool -> ture/false

2. 格式化输出

   Console.WriteLine(**$**"...{*name*}...");   {*name*} -> 变量名称  **（此方法仅限C#6 +）**
   
   Console.WriteLine("args1:{0} ,args2:{1}",value1,value2);
   
   Console.WriteLine(string.Format("args1:{0} ,args2:{1}",value1,value2));
   
   

#### 第5章

1. 初始化数组：

   int[] myIntArray = { 5, 9, 10, 2, 99 };

   int[] myIntArray = new int[5];

   或

   int[] myIntArray; 

   myIntArray = new int[5];

2. <...>.Length语句来确定<...>对象长度

3. foreach循环对数组内容进行**只读**访问，所以不能改变任何元素的值

   foreach (< base Type > < name > **in** < array>) {...}

4. < srting >**.ToLower()**

   < srting >**.ToUpper()**

   < srting >**.Trim()**	删除输入字符串前后的空格

5. 为获得一个可写的char数组

   string myString = "A string"; 

   char[] myChars = myString**.ToCharArray()**;

6. String**.PadLeft**(10,'0'),就是检查字符串长度是否超过10，不超过的左侧加0补足到10的长度

   String**.PadRight**同理

7. String**.Replace**("a", "b"),用b替换a

8. myString = "content" + myString + "content";可直接在字符串前后增加内容

9. < string >.Split('...')识别string里的'...'并去除后分割string成string数组

   

## 第6章

1. static double Multiply (double a, double b) **=>** a * b;	表达式体方法,函数模式使用**=>**（Lambda箭头）来实现这一功能。

2. static < type > SumVals ( **params**  < type >[]  vals ){}    

   用关键字**params**定义函数sumVals()，该函数可以接受任意 个type型参数（但不接受其他类型的参数）

   详见p238

3. static void ShowDouble(**ref** int val){}

   用关键字**ref**定义函数ShowDouble()，可以使main函数的实参输入ShowDouble函数后改变

   **把未赋值的变量用作ref参数是非法的**

4. static int MaxValue(int[] intArray, **out** int maxIndex)

   在函数使用out参数时，必须把它看成尚未赋值，已赋值的变量的值也会在函数执行时丢失。

5. 必须使用static或const关键字来定义全局变量

6. string**.Substring(a, b)** ;   检索从a位置开始**b个长度**的字符串

   参数一 (a)：起始位置

   参数二 (b)：指定长度

7. string**.IndexOf("ex")**； 查找“ex”在string中的索引值（位置）

8. 委托是类似于指向函数的指针

   + 1.定义委托

     **delegate** double ParocessDelegate(double param1,double param2);

   + 2.声明委托类型的变量

     ProcessDelegate process;

   + 3.初始化委托变量

     process = new ProcessDelegate( < 函数名 > );

## 第7章 

1. 断点
2. F5开启调试
3. F11逐语句执行



## 第9章

1. 密封类（不可被继承）public **sealed** class MyClass 

2. 抽象类（只能继承，可以有抽象成员）public **abstract** class MyClass

3. 指定继承 public class MyClass **:** MyBase

   注：如果继承了一个抽象类，就必须实现所继承的所有抽象成员（除非派生类也是抽象的）