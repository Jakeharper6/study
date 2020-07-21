  /*
      从输入的整数开始倒数到0
    当输入的值为负数的时候不执行换行操作
  */

#include <stdio.h>

int main(void)
{
    int no;

    printf("请输入一个正整数：");
    scanf("%d", &no);

    if(no >= 0){
    while (no >= 0) {
        printf("%d ", no);
        no--;}
    }
    else
    {
      printf("不在取值范围内");
    }
    

    return 0;
}