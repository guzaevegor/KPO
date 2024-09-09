/*№13. Дано натуральное число n. Вычислить:
а)Сумму ряда от k=1 до n по функции f(x) = 1/k
б)Сумму ряда от k=1 до n по функции f(x) = 1/(2k+1)^2*/
#include <stdio.h>
int main(void)
{
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    double suma = 0;
    for ( int i = 1; i <= n; i++)
    {
        suma += 1.0 / i;
    }
    printf("Suma = %f \n", suma);
    double sumb = 0;
    for ( int i = 1; i <= n; i++)
    {
        sumb += 1.0 / ((2 * i + 1) * (2 * i + 1));
    }
    printf("Sumb = %f \n", sumb);
    return 0;
}
