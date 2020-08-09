/*编写如下set_idx函数，接收元素类型为int型、元素个数为n的数组，并为所有元素赋上和下标相同的值。
void set_idx(int *v,int n)*/

#include<stdio.h>
#define Number 5

void set_idx(int *v,int n){
    for (int i = 0; i < n; i++)
    {       
        *(v + i) = i;
    }    
}

int main(void){
    int a[Number];
    printf("Enter blow:\n");
    scanf("%s",a);
    
    set_idx(a,Number);

    printf("help you transform:\n");
    for (int i = 0; i < Number; i++)
    {
        printf("%d",a[i]);
    }
    
    return 0;
}