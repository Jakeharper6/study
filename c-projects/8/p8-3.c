/*定义一个函数式宏swap(type，a，b)以使type型的两值互换。
例如:假设int型变量x、y的值分别为5、10,那么调用swap(int,x,y)后，x、y中应分别保存10、5。*/

#include <stdio.h>
#define swap(int,a,b) {int temp;temp = a;x = y;y = temp;}

int main(void){
    int x = 5;
    int y = 10;
    swap(int, x, y);
    printf("x = %d\ny = %d\n", x, y);
    return 0;
}