/*编写一段程序，使之交替显示+和-，总个数等于所输入的整数值。另外，当输入0以下的整数时，则什么也不显示。
+-+-+-+-+-+-+-+-+-+-+-+-
*/

#include<stdio.h>
void main()
{
    int a;
    puts("请输入整数a：");scanf("%d",&a);
    
    if(a > 0){
        
        while(a > 0){

        if(a%2)
            putchar('+');
        
        else 
            putchar('-');
        a--;
        }
    }
    else printf("无");

    return 0;
}

