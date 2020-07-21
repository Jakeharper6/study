/*编写一段程序，读取数组中的数据个数和元素值并显示。显示时，各值之间用逗号和空格分割，并用大括号将所有值括起来。
注意利用对象式宏来声明数组的元素个数，如代码清单5-12那样。*/


#include <stdio.h>

#define number    80    

int main(void)
{
    int v[number];
    int num;
    int i;
    printf("数据个数:");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        printf("%d号:",i+1);
        scanf("%d", &v[i]);
    }
    printf("{");
    for (i = 0; i < num-1; i++) {
        
        
        printf("%d, ", v[i]);
    }
    printf("%d", v[num-1]);
    printf("}");
    


    return 0;
}
