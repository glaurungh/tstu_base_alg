#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main() {
    int a, b, data[N], i, min, found = 0;
    printf("Введите a, b: ");
    scanf("%d %d", &a, &b);
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (i = 0; i < N; i++) {
	data[i] = a + rand() % (b - a + 1); // Генерация случайных чисел в заданном диапазоне
        printf("%d ", data[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        if (data[i] % 2 != 0) {
            if (!found || data[i] < min) {
                min = data[i];
                found = 1;
            }
        }
    }

    if (found)
        printf("Минимальный нечётный элемент: %d\n", min);
    else
        printf("Нечётных элементов нет.\n");
    return 0;
}
