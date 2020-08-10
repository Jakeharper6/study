/*将代码清单11-3中对p的赋值进行如下修改。
p = "456" + 1;
请编写程序确认运行结果，并对运行结果进行分析。*/

/*
    用指针实现的字符串的改写
*/
#include <stdio.h>

int main(void)
{
    char *p = "123";
    printf("p = \"%s\"\n", p);
   
    p = "123456";
    printf("p = \"%s\"\n", p);
   
    p = "456" + 1; //指向元素'4'后移一位地址
    printf("p = \"%s\"\n", p);

    return 0;
}