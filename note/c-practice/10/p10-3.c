/*编写如下函数，将n1、n2、n3指向的三个int型整数按升序排列。
void sort3(int *n1,int *n2,int *n3)*/
#include<stdio.h>

void sort(int *n1,int *n2,int *n3){
    int temp;
    if (*n2 < *n1)
    {
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
    }

    if (*n3 < *n2)
    {
        temp = *n2;
        *n2 = *n3;
        *n3 = temp;

        if (*n2 < *n1)
        {
            temp = *n1;
            *n1 = *n2;
            *n2 = temp;
        }
    }
    
}

int main(void){
    int a, b, c;
    
    printf("输入三个数：\n");
    printf("第一个数：");
    scanf("%d",&a);
    printf("第二个数：");
    scanf("%d",&b);
    printf("第三个数：");
    scanf("%d",&c);

    sort(&a,&b,&c);
    printf("升序排列为：%d,%d,%d",a,b,c);

    return 0;
}