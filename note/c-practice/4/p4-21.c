//编写一段程序，显示以所输入整数为边长的正方形。

#include<stdio.h>

int main(void){

    int i , j ,len;

    printf("输入正方形的边长:");
    scanf("%d",&len);

    for ( i = 1; i <= len; i++)
    {
        for ( j = 1; j <= len; j++)
        {
           printf("%3s","*") ;
        }
        printf("\n");
        
    }
    
}