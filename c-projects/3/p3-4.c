/*编写一段程序，输入两个整数，如果两数值相等，则显示“A和B相等。”。
如果A大于B,则显示“A大于B。”。如果A小于B,则显示“A小于B。”。
整数A：54
整数B：12
A大于B*/

#include<stdio.h>

int main(void){

    int a,b;

    puts("请输入两个整数");
    printf("整数A:");scanf("%d",&a);
    printf("整数B:");scanf("%d",&b);
    if (a == b)
       puts("A和B相等。");
    
    else if (a > b)
       puts("A大于B。");
    
    else
       puts("A小于B。");

    return 0;
}