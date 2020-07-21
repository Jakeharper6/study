/*编写一段程序，输入一个整数，显示出输入整数层的金字塔形状。 提示:第i行显示(i-1)*2+1个'*'。
让我们来画一个金子塔。
金字塔有几层：3
  *
 ***
*****
*/

#include<stdio.h>

int main(void){

    int no, i, j, x;

    printf("输入一个正整数:");
    scanf("%d",&no);

    for ( i = 1; i <= no; i++)
    {
        for ( j = 0; j < no - i; j++)
        {
            printf(" ");
        }

        for ( x = 0; x < (i - 1) * 2 + 1 ;x++)
        {
            printf("*");
        }
    
    printf("\n");    
        
    }
    
}