#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double value, a, S, h, r, R;
    const double sqrt3 = sqrt(3);
    
    printf("Выберите элемент (1-5):\n");
    printf("1 - сторона a\n");
    printf("2 - площадь S\n"); 
    printf("3 - высота h\n");
    printf("4 - радиус вписанной r\n");
    printf("5 - радиус описанной R\n");
    scanf("%d", &choice);
    
    printf("Введите значение: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: a = value; break;
        case 2: a = sqrt(4 * value / sqrt3); break;
        case 3: a = 2 * value / sqrt3; break;
        case 4: a = 2 * value * sqrt3; break;
        case 5: a = value * sqrt3; break;
        default: 
            printf("Неверный выбор\n");
            return 1;
    }
    
    // Вычисление остальных элементов
    S = a * a * sqrt3 / 4;
    h = a * sqrt3 / 2;
    r = a * sqrt3 / 6;
    R = a * sqrt3 / 3;
    
    printf("\nРезультаты:\n");
    printf("Сторона a = %.6lf\n", a);
    printf("Площадь S = %.6lf\n", S);
    printf("Высота h = %.6lf\n", h);
    printf("Радиус вписанной r = %.6lf\n", r);
    printf("Радиус описанной R = %.6lf\n", R);
    
    return 0;
}
