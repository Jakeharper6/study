/*编写一段程序，读取两个整数，然后显示出前者是后者的百分之几。*/

#include<stdio.h>

int main(void){

    int a,b;

    puts("输入两个整数");

    printf("整数1:");scanf("%d",&a);
    printf("整数2:");scanf("%d",&b);

    printf("整数1是整数2的%.0f%%\n",(double)a/b*100);

    return 0;
}