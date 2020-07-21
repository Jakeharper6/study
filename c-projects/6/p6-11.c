/*创建一个函数search_idx,将和有n个元素的数组v中的key相等的所有元素的下标存储在数组idx中，返回和key相等的元素的个数。
int search_idx(const int v[] int idx[],int key,int n);
例如，如果v中所接收的数组的元素是{1,7,5,7,2,4,7},key为7的话,{1,3,6}就会被存储在id中x，并返回3。*/

#include <stdio.h>
#define number 5

int search_idx(const int v[], int idx[], int key, int n)
{

    int i;
    int x = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == key)
        {
            idx[x] = i;
            x++;
        }
    }
    return x;
}

int main()
{
    int v[number];
    int y[number + 1];

    int i;
    int key;
    printf("要查找的值是：");
    scanf("%d", &key);
    for (i = 0; i < number; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }
    int x = search_idx(v, y, key, number);
    printf("有%d个相同的元素", x);
}