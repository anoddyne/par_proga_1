#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func_12(double n, double a, double b, double I) {
    double h = (b - a) / n;
    for (int i = 0; i < n - 1; i++) {
        I = I + sin(a += h);
    }
    I = I * h;
    return I;
}

double simpson(double n, double a, double b) {
        double h = (b - a) / n;
        double even_x = a, odd_x = a+h;
        double I = 0;
        for (int i = 0; i < n; i++) {
            I += sin(even_x) + 4 * sin(even_x + h / 2) + sin(odd_x);
            even_x += h;
            odd_x += h;
        }
        I = (h / 6) * I;
        return I;
    }
    
int main()
{
    int n, choice;
    double h = 0;
    double a, b, I;
    printf("Choose which method to use to calculate the area of a curvilinear trapezoid: 1 - left rectangle method, 2 - trapezoid method, 3 - Simpson method: \n");
    scanf("%d", &choice);
    switch (choice) {
    case(1):
        printf("The left rectangle method: \n");
        printf("Enter the desired segment [a, b]:");
        scanf("%lf%lf", &a, &b);
        printf("Enter the desired number of partitions of the segment: ");
        scanf("%d", &n);
        I = sin(a);
        printf("%lf", func_12(n, a, b, I));
        break;
    case(2):
        printf("Trapezoid method: \n");
        printf("Enter the desired segment [a, b]:");
        scanf("%lf%lf", &a, &b);
        printf("Enter the desired number of partitions of the segment: ");
        scanf("%d", &n);
        I = (sin(a) + sin(b)) / 2;
        printf("%lf",func_12(n, a, b, I));
        break;
    case(3):
        printf("Simpson method: \n");
        printf("Enter the desired segment [a, b]:");
        scanf("%lf%lf", &a, &b);
        printf("Enter the desired number of partitions of the segment: ");
        scanf("%d", &n);
        printf("%lf", simpson(n, a, b));
        break;
    default:
        printf("Enter the number from 1 to 3.");
    }
}