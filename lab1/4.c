/*№ 23. Дано натуральное число n, целые числа а1, а2, ..., аn. Получить сумму положительных 
и число отрицательных членов последовательности а1, а2, ..., аn.*/ 
#include <stdio.h>

int main(void)
{
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    int a[n];
    printf("Input numbers: ");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int sum_positive = 0;
    int count_negative = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] > 0){
            sum_positive += a[i];
        }
        if (a[i] < 0){
            count_negative++;
        }
    }
    printf("Sum of positive numbers: %d\n", sum_positive);
    printf("Count of negative numbers: %d\n", count_negative);
    return 0;
}