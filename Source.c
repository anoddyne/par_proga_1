/* Documentation 

Left Rectangle Method:
The area of a curvilinear trapezoid is calculated by dividing the figure into rectangles, 
which together form an area similar to the original trapezoid. Then the area for each 
rectangle is calculated, and all the areas of the rectangles are added together.
First we take a function that is continuous on the interval [a, b]. This segment is divided 
into n equal parts. The length of each segment is determined by the formula h = (a + b) / n, 
where: a = x0 < x1 < x2 < ... < x(n-1) < xn = b. The area of a curvilinear trapezoid is calculated 
by multiplying the length of the segment by the sum of the functions at the points x0, x1, x2, ..., x(n-1), xn.

Trapezoid Method:
This method uses a similar concept as the left rectangle method. Here, the value of the function
is calculated using the formula for the area of a trapezium: S = 1/2 * h * (a + b), 
where h is the length of each segment. Instead of the sum of parallel sides (a + b) in the formula 
we substitute the sum of functions in points x0, x1, x2, ..., x(n-1), xn (x0 = a, xn = b). 
The result is a function: S(trapezoid) = 1/2 * h * (f(x0) + f(x1) + f(x2) + ... + f(x(n-1)) + f(xn)).

Simpson's method:
Simpson's method uses a parabola to calculate the area of a curvilinear trapezoid. We take a function 
that is continuous on the interval [a, b]. Split the segment into an even number of equal segments (2*n). 
The partition has the form: [x0; x1], [x1; x2], [x2; x3], ..., [x(2n-2); x(2n-1)], [x(2n-1); x(2n)] (x0 = a, xn = b). 
Simpson's formula has the following form: I = 1/3 * h * (f(a) + 4 * f(a+h/2) + f(b)), where h = (a + b) / (2*n).
*/




#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
        double even_x = a, odd_x = a + h;
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
        break;
    }
}