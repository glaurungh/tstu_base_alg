#include <stdio.h>
#include <math.h>

int main() {
    double eps, s = 0, sl, sr;
    int k = 1;
    
    printf("Введите точность ε: ");
    scanf("%lf", &eps);
    
    sl = 1 / ((2.0 * k - 1) * 2.0 * k * (2.0 * k + 1));

    
    while(fabs(sl) > eps) {
        s += sl;
        k++;
        sl = 1.0 / ((2.0*k - 1) * 2.0*k * (2.0*k + 1));
    	//printf("sl=%lf\n", sl);
    }
    
    sr = log(2.0) - 0.5;
    
    printf("s = %lf, sr = %lf\n", s, sr);
    return 0;
}
