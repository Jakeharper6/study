//创建一个函数，返回元素个数为n的int型数组v中的最小值。

#include <stdio.h>

#define NUMBER    5

/*找出数组中的最小值*/
int set_min(const int v[], int n)
{
    int min;
    min = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] <= min)
        {
            min = v[i];
        }
    }

    return min;   
}


int main(void)
{
    int x;
    int m[NUMBER];
    
    printf("请输入一组数\n");
    for (x = 0; x < NUMBER; x++)
    {
        printf("%d号:",x + 1);
        scanf("%d",&m[x]);
    }
    
    printf("其中最小值为%d",set_min(m,NUMBER));

    return 0;
}