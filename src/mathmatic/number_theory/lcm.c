#include<stdio.h>
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b)
{
    int num = gcd(a, b);
    return a/num*b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int num, res=1;
        for(int i=0;i<n;++i){
            scanf("%d", &num);
            res = lcm(res, num);
        }
        printf("%d\n", res);
    }
    return 0;
}