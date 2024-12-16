#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 4;

    // Integer division is performed between a and b,
    // and the result is then converted to a float.
    float res = a / b;
    printf("%.1f\n", res); // 2.0

    // If we type-cast `a` to a float, the compiler
    // will treat the whole operation as a float
    // division, returning the expected result.
    res = (float)a / b;
    printf("%.1f\n", res); // 2.5
    return 0;
}
