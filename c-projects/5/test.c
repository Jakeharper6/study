#include <stdio.h>

int main(void){
    
    int n;

    for (n = 0; n <= 10; n++)
    {
        printf("------");
    }

    printf("\n");

    for (n = 0; n <= 10; n++)
    {
        printf("%5d", n * 10);
    }

    return 0;
}