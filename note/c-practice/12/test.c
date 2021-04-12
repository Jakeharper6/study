#include <stdio.h>

int main(void)
{
    int n = 10;
    int a[10] = { 7,1,10,4,3,9,2,6,5,8 };

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            
        }
        
    }

    for (int i = 0; i < n ; i++)
    {
        printf("%d", a[i]);
    }

}