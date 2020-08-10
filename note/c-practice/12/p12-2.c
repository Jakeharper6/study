/*代码清单12-5的程序中，结构体对象sanaka的各成员的值都有初始值。
改写这个程序，声明时不为其赋初始值，而且各成员的值从键盘输入。*/

/*
拥有超能力的洋子（在结构体中引入typedef名）
*/
#include <stdio.h>

#define NAME_LEN 64

struct student {        /*student可以省略*/
    char name[NAME_LEN];   /*姓名*/
    int height;            /*身高*/
    float weight;          /*体重*/
    long schols;           /*奖学金*/
};

int main(void){
    struct student sanaka;

	printf("请输入姓名为:");	scanf("%s",&sanaka.name);
	printf("请输入身高为:");	scanf("%d",&sanaka.height);
	printf("请输入体重为:");	scanf("%f",&sanaka.weight);
	printf("请输入奖学金为:");	scanf("%ld",&sanaka.schols);
		
    printf("姓名 = %s\n", sanaka.name);
    printf("身高 = %d\n", sanaka.height);
    printf("体重 = %.1f\n", sanaka.weight);
    printf("奖学金 = %ld\n", sanaka.schols);
	
    return 0;
}