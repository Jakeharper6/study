/*创建一个函数，对元素个数为n的int型数组v进行倒序排列。
void rev_intary{int v[],int n)*/

#include<stdio.h>

#define NUMBER 5

void rev_intary(int v[],int n)
{
    int i;
    for ( i = n; i > 0; i--)
    {
        printf("%d",v[i-1]);
    }
    
}

int main(void)
{
    int x;
    int m[NUMBER];

    printf("请输入一组数\n");
    for (x = 0; x < NUMBER; x++)
    {
        scanf("%d",&m[x]);
    }

    printf("这组数倒序排列如下\n");
    rev_intary(m,x);

    return 0;
}