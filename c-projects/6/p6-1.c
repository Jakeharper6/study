//创建一个函数，返回两个int型整数中较小一数的值。int min2(int a,int b){/*...*/}

#include<stdio.h>

int min2(int a,int b){
	if (a < b)
		return a;
	else
		return b;
}

int main(void){
	int n1 , n2;

	printf("请输入两个整数\n");
	printf("整数1:");scanf("%d",&n1);
	printf("整数2:");scanf("%d",&n2);

	printf("较小的数是:%d",min2(n1,n2));
}