//创建一个函数，返回1到n之间所有整数的和。int sumup(int n){/*...*/}

#include <stdio.h>

int sumup(int n) {
    int i ;
	int sum = 0;
	for (i = 0; i < n; n--)
	{	
        sum += n;
    }    
    
	return sum;
}


int main(void) {
    int x;
    
    printf("请输入一个数:");
    scanf("%d", &x);
    printf("从1到%d之间所有整数的和是%d",x, sumup(x));
        
    return 0;
}