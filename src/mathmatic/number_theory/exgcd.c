#include<stdio.h>

long long exgcd(long long a,long long b, long long *x, long long *y)
{
    if(b==0){
        *x=1;
		*y=0;
        return a; 
    }
    long long r=exgcd(b,a%b,x,y);
    long long temp=*y;
    *y=*x-(a/b)* *y;
    *x=temp;
    return r;
}

int main()
{
	long long x,y,m,n,L;
	scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L);
	long long a = n-m;
	long long b = L;
	long long c = x - y;
	if(a<0){
		a = -a;
		c = -c;
	}
	long long gcd = exgcd(a, b, &x, &y);
	if(c%gcd!=0) printf("Impossible\n");
    else{
        x=x*c/gcd;
        long long temp = L/gcd;
        if(x>=0)
            x=x%temp;
        else
            x=x%temp+temp;
        printf("%lld\n",x);
	}
	return 0;
}