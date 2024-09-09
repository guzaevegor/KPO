/*
№27. Дано натуральное число n. Получить все такие натуральные q, что n делится на q^2 и не делится на q^3.*/
#include <stdio.h>
 
int main() {
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    int flag = 0;
    for ( int q = 1; q <= n; q++ ) {
        if ( (n % (q * q) == 0 )&& (n % (q * q * q) != 0 ) ) {
            printf("%d\n", q);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No such q\n");
    }
    return 0;
}