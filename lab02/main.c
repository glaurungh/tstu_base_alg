#include <stdio.h>

int main() {
    int a, b, c, k = 0;
    
    printf("Введите a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a < c) k++;
    if (b < c) k++;
    
    printf("Количество чисел меньших %d: %d\n", c, k);
    return 0;
}
