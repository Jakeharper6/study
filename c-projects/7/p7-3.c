#include <stdio.h>
#include<math.h>
unsigned rrotate(unsigned x,int n){
    x >>=n;
    return x;
}

int main() {
    unsigned int number;
    int x;
    printf("请输入初始值:");
    scanf("%d", &number);
    printf("右移多少位:");
    scanf("%d", &x);


    printf("右移后的值:%d", rrotate(number, x));

}