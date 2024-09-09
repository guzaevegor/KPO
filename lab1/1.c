#include <stdio.h>
/*№11. Даны действительное число а, натуральное число n. Вычислить:
а) a^n
б) a(a+1)...(a+n-1)*/
int main(void)
{
    double a;
    int n;
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input n: ");
    scanf("%d", &n);
    
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= a;
    }
    
    printf("a^n = %.2f \n", result);

    result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= (a + i);
    }
    printf("a(a+1)...(a+n-1) = %.2f \n", result);

    return 0;
}