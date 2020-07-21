#include <stdio.h>

int main() {
    int n;
    printf("%d\t%d\t%d\n", sizeof 1,sizeof(unsigned)-1,sizeof n+2 );                                                                 
    printf("%d\t%d\t%d\n", sizeof +1, sizeof(double) - 1, sizeof(n + 2));
    printf("%d\t%d\t%d\n", sizeof - 1, sizeof((double)-1), sizeof (n + 2.0)  );
}