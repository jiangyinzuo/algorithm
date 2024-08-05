#include<cstdio>
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    int s, n, m;
    while(scanf("%d %d %d", &s, &n, &m) && s && n && m){
        s /= gcd(n, m);
        if(s%2 == 1) printf("NO\n");
        else printf("%d\n", s-1);
    }
    return 0;
}