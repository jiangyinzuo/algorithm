#include<cstdio>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int c = b * 2;
        while (1) {
            if (gcd(a, c) == b) {
                printf("%d\n", c);
                break;
            }
            c += b;
        }
    }
    return 0;
}