# C#入门经典

## 3

1. **W**rite**L**ine等语法大小写

2. using **static** System. Console(/Convert...);

   **ToInt32()**和**ToDouble()**方法是 System. Convert静态类的一部分

3. 用于在程序结束前 等待用户输入内容： Console**.ReadKey()**;

## 4

1. bool < name >  = < ... >; 	bool -> ture/false
2. WriteLine(**$**"...{name}...");      {name} -> 变量名称

## 5

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