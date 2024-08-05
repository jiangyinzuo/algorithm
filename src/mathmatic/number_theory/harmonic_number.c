#include<stdio.h>
#include<math.h>
double s[30001];
int main()
{   
    s[1] = 1;
    s[2] = 1.5;

    for(int i=3;i<=20000;++i){
        s[i] = s[i-1] + 1.0/i;
    }
    int t;
    scanf("%d", &t);
    for(int j=1;j<=t;++j){
        int n;
        scanf("%d", &n);
        if(n<=18888) printf("Case %d: %.10lf\n", j, s[n]);
        else
            printf("Case %d: %.10lf\n", j,log(n)+0.57721566490153286060651209+1.0/(2*n));
    }
    return 0;
}