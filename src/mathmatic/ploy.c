#include <stdio.h>

double ploy(int n, double x) {
    double answer = 0;
    while (n) answer = answer * x + (n-- & 1 ? -1 : 1);
    return answer;
}

int main() {
    printf("%lf", ploy(3, 2));
    return 0;
}
