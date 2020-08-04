/*对代码清单4-6的程序进行修改，使其
•递减到1而非递减到0。
•当输入的值小于0时，不进行换行。
*/

#include <stdio.h>

int main(void)
{
    int no;

    printf("请输入一个大于1的正整数：");
    scanf("%d", &no);

    if(no >=1){
        while (no >= 1) {
        printf("%d ", no);
        no--;
    }
    }
    else printf("不在取值范围内");

    return 0;
}