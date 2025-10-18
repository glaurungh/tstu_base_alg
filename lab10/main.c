#include <stdio.h>

int main() {
    long long n, temp;
    int digits = 0, i, sum = 0;
    printf("Введите n (>9): ");
    scanf("%lld", &n);
    temp = n;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    int half = (digits + 1) / 2;
    temp = n;
    for (i = 0; i < digits - half; i++) temp /= 10;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    printf("Сумма первой половины: %d\n", sum);
    return 0;
}
