#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001 
#define MAX_ITER 100    


double equation(double x) {
    return x * x - 4;
}


void secantMethod(double x0, double x1) {
    double x2, f_x0, f_x1, f_x2;
    int iterations = 0;

    do {
        f_x0 = equation(x0);
        f_x1 = equation(x1);

        if (f_x0 == f_x1) {
            printf("Secant method failed. Division by zero.\n");
            return;
        }

        x2 = x1 - (f_x1 * (x1 - x0)) / (f_x1 - f_x0);
        f_x2 = equation(x2);

        x0 = x1;
        x1 = x2;

        iterations++;
    } while (fabs(f_x2) > EPSILON && iterations < MAX_ITER);

    printf("Estimated root: %lf\n", x2);
    printf("Functional value at root: %lf\n", f_x2);
    printf("Required number of iterations: %d\n", iterations);
}

int main() {
    double x0, x1;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter initial guess x1: ");
    scanf("%lf", &x1);

    secantMethod(x0, x1);

    return 0;
}
