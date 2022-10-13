#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double func_12(double n, double a, double b, double h, double I) {
    h = (b - a) / n;
    for (int i = 0; i < n - 1; i++) {
        I = I + sin(a += h);
    }
    return h * I;
}

double simpson(double n, double a, double b, double h, double I) {
    h = (b - a) / n;
    double chet_slag = sin(a + h), nechet_slag = sin(a + h);

    for (int i = 1; i <= n; i++) {
        chet_slag += 2 * sin(2 * i - 2);
        nechet_slag += 4 * sin(2 * i - 1);
    }
    I = sin(a) + sin(b) + chet_slag + nechet_slag;
    return (h / 6) * I;
}

int main()
{
    int n, choice;
    double h = 0, I = 0;
    double a, b;
    printf("Choose which method to use to calculate the area of a curvilinear trapezoid: 1 - left rectangle method, 2 - trapezoid method, 3 - Simpson method");
    scanf("%d", &choice);
    switch (choice) {
    case(1):
        printf("The left rectangle method: \n");
        printf("Enter the desired segment [a, b]:");
        scanf("%lf%lf", &a, &b);
        printf("Enter the desired number of partitions of the segment: ");
        scanf("%d", &n);
        I = sin(a);
        printf("%lf", func_12(n, a, b, h, I));
        break;
    case(2):
        printf("Trapezoid method: \n");
        printf("Enter the desired segment [a, b]:");
        scanf("%lf%lf", &a, &b);
        printf("Enter the desired number of partitions of the segment: ");
        scanf("%d", &n);
        I = (sin(a) + sin(b)) / 2;
        printf("%lf",func_12(n, a, b, h, I));
        break;
    case(3):
        printf("Simpson method: ");
        printf("Enter the desired segment [a, b]:");
        scanf("%lf%lf", &a, &b);
        printf("Enter the desired number of partitions of the segment: ");
        scanf("%d", &n);
        printf("%lf", simpson(n, a, b, h, I));
        break;
    default:
        printf("Enter the number from 1 to 3.");
    }
}