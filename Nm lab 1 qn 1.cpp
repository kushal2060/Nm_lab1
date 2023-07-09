#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001 
#define MAX_ITER 100    


double equation(double x) {
    return x * x - 4;
}


void halfIntervalMethod(double a, double b) {
    double fa, fb, fc, c;
    int iterations = 0;

    fa = equation(a);
    fb = equation(b);

    if (fa * fb >= 0) {
        printf("Initial guesses do not bracket the root.\n");
        return;
    }

    do {
        c = (a + b) / 2.0;
        fc = equation(c);

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        iterations++;
    } while (fabs(fc) > EPSILON && iterations < MAX_ITER);

    printf("Estimated root: %lf\n", c);
    printf("Functional value at root: %lf\n", fc);
    printf("Required number of iterations: %d\n", iterations);
}

int main() {
    double a, b;

    printf("Enter initial guess a: ");
    scanf("%lf", &a);

    printf("Enter initial guess b: ");
    scanf("%lf", &b);

    halfIntervalMethod(a, b);

    return 0;
}
