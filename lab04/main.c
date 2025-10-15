#include <stdio.h>

int main() {
    int n, i;
    long a, s;
    
    printf("Введите n: ");
    scanf("%d", &n);
    
    a = 4;
    s = a;
    
    for(i = 2; i <= n; i++) {
        a = 5 * a + 3;
        s += a;
    }
    
    printf("Сумма первых %d элементов: %ld\n", n, s);
    return 0;
}
