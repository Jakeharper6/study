/*编写一个函数，使字符串s为空字符串。
void null_string(char s[])*/

#include<stdio.h>

void null_string(char s[]){
	s[0]='\0';
}

int main(void)
{
	char ch[128];
    printf("请输入字符串: ");
    scanf("%s", ch);
    null_string(ch);
    printf("字符串为\"%s\"\n", ch);

    return 0;
}
