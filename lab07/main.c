#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define M 4

int main() {
    int a, b, data[N][M], i, j, max, found = 0;
    printf("Введите a, b: ");
    scanf("%d %d", &a, &b);
    srand(time(NULL));;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            data[i][j] = a + rand() % (b - a + 1);
            printf("%4d", data[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (data[i][j] % 2 != 0) {
                if (!found || data[i][j] > max) {
                    max = data[i][j];
                    found = 1;
                }
            }
        }
    }

    if (found)
        printf("Максимальный нечётный элемент: %d\n", max);
    else
        printf("Нечётных элементов нет.\n");
    return 0;
}
