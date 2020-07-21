//创建一个函数，对元素个数为n的int型数组v2进行倒序排列，并将其结果保存在数组v1中。

#include<stdio.h>

#define NUMBER 5

void rev_intary(int v1[],const int v2[],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        v1[i] = v2[n - i - 1];
    }
    
    for ( i = 0; i < n; i++)
    {
        printf("%d",v1[i]);
    }
    
}

int main(void)
{
    int x;
    int m[NUMBER];
    int m2[NUMBER];

    printf("请输入一组数\n");
    for (x = 0; x < NUMBER; x++)
    {
        scanf("%d",&m2[x]);
    }

    printf("这组数倒序排列如下\n");
    rev_intary(m,m2,x);

    return 0;
}