//创建一个函数，返回int型整数的立方。int cube(int x){/** * * */}

#include<stdio.h>

int cube(int x){
	return x*x*x;
}

int main(void){
	int no;
	
	printf("输入一个整数:\n");
	scanf("%d",&no);

	printf("该整数的立方是:%d",cube(no));

	return 0;
}