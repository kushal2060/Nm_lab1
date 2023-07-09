#include <stdio.h>

// Function to evaluate a polynomial using Horner's method
double horner(double coefficients[], int degree, double x) {
    double result = coefficients[0];

    for (int i = 1; i <= degree; i++) {
        result = result * x + coefficients[i];
    }

    return result;
}

int main() {
    int degree;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    double coefficients[degree + 1];

    printf("Enter the coefficients in descending order of powers:\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", degree - i);
        scanf("%lf", &coefficients[i]);
    }

    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    double result = horner(coefficients, degree, x);

    printf("Result of polynomial evaluation: %lf\n", result);

    return 0;
}
