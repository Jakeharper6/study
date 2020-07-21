//改写代码清单4-8的程序，当输入的值小于1时不输出换行符。
/*
输入一个整数，连续显示出该整数个数*
*/

#include<stdio.h>
void main()
{
    int a;
    puts("请输入整数a：");scanf("%d",&a);
    
    if(a > 0){
        while(a > 0){
        putchar('*');
        a = a - 1;}
    }
    else printf("无");
}