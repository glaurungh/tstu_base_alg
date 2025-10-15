#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, y;
    
    printf("Введите a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    y = (pow(tan(a), 2) - b * c) / (b * acos(b*b + c*c));
    
    printf("y = %.6lf\n", y);
    return 0;
}
