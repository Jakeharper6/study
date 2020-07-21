/*创建函数put_count，显示被调用的次数(如下显示的是调用3次函数put_count的运行结果)
void put_count()
put_count:第一次
put_count:第二次
put_count:第三次*/

#include <stdio.h>


void put_count() {
    static int i = 1;
    printf("put-count:第%d次", i++);
    putchar('\n');

}

int main() {
    int i;
    for (i = 0; i < 5; i++) {
        put_count();
    }
}