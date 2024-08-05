#include<stdio.h>
int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) && a && b){
        int res = 1;
        while(b >=1) {
            if(b&1){
                res *= a;
            }
            b/=2;
            a *= a;
            res %= 1000;
            a %= 1000;
        }
        printf("%d\n", res);
    } 
    return 0;
}