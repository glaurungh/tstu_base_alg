#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, y;
    double f(double,double,double);
    
    printf("Введите a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    y = f(a, b, c);
    
    printf("y = %.6lf\n", y);
    return 0;
}

double f(double a, double b, double c) {
    return (pow(tan(a), 2) - b * c) / (b * acos(b*b + c*c));
}
