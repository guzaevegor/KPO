#include <stdio.h>
/*№12. Вычислить сумму ряда от i = 1 до 50 по функции f(x) = 1/i^3*/
int main(void)
{
    double sum = 0;
    for (int i = 1; i <= 50; i++)
    {
        sum += 1.0 / i * i * i;
    }
    printf("Sum = %f \n", sum);
    return 0;
}


