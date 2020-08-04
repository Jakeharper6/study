//对代码清单4-10的程序进行修改，使其在显示结果的同时显示输入的整数值。

#include<stdio.h>

int main(void){

    int a;

    do{
        printf("请输入正整数:");
        scanf("%d",&a);

        if(a <= 0)
        printf("请不要输入非正整数!\n");
    }while(a <= 0);

    printf("该整数%d逆向显示的结果是：",a);
    while(a > 0){
        printf("%d",a % 10);
        a /= 10;
    }

    return 0;
}