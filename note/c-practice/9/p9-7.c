/*编写如下函数，使字符串s显示n次。
void put_stringn(const char s[],int n)
例如，若s和分别为"ABC"和3,则显示"ABCABCABC"。*/
#include<stdio.h>
#define Number 20

void put_stringn(char s[],int n){
    
    for (int i = 0; i < n; i++)
    {
        printf("%s",s);
    }
    
}

int main(void){
    char a[Number];
    int n;

    printf("输入一串字符：\n");
    scanf("%s",a);
    printf("输入想要显示的次数：\n");
    scanf("%d",&n);

    put_stringn(a,n);

    return 0;
}