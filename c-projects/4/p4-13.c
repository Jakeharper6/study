//编写一段程序，求1到n的和。n的值从键盘输入

#include<stdio.h>

int main(){
    
    int n;
    int x;
    int y;
    

    puts("请输入一个正整数");
    printf("整数n:");scanf("%d",&n);
    
    x = 0;
    y = n;
    do{
       x = x + y ;
       y --;
    }while(y > 0 );

    printf("1到n的和为%d",x);

    return 0;
}