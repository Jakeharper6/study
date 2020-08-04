  /*
      从输入的整数开始倒数到0
    当输入的值为负数的时候不执行换行操作
  */

#include <stdio.h>

int main(void)
{
    int n;
    int i;

    do
    {
      printf("请输入一个正整数：");
      scanf("%d", &n);

      if (n < 0)
      {
        printf("请不要输入负数！！！\n");
      }
      
    } while (n < 0);
    
    for ( i = n; i > 0; i--)
    {
      printf("%d",i);
    }
    

    return 0;
}