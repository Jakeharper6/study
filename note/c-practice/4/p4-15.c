/*编写一段程序，显示出身高和标准体重的对照表。显示的身高范围和间隔由输入的整数值进行结控制，标准体重精确到小数点后2位。
开始数值（cm）：155
结束数值（cm）：190
间隔数值（cm）：5

155cm    49.50kg
160cm    54.00kg
...(以下省略)...
*/

#include<stdio.h>

int main(void){

    int a,b,c,i;
    printf("开始数值(cm):");scanf("%d",&a);
    printf("结束数值(cm):");scanf("%d",&b);
    printf("间隔数值(cm):");scanf("%d",&c);

    for (i = a; i <= b; i = i + c)
    {
        printf("%dcm   %5.2fkg\n",i,(i - 100) * 0.9);
    }
    

    return 0;
}