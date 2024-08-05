#include<cstdio>
using namespace std;
long long f[109][109];
long long temp[109][109];
long long resMatrix[109][109];

long long max(long long a, long long b)
{
    return a>b?a:b;
}

void multiple(long long x[109][109], long long y[109][109], int m)
{
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            temp[i][j] = 0;
            for(int k=1;k<=m;k++){
                temp[i][j] = max(temp[i][j], x[k][j]+y[i][k]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            y[i][j]=temp[i][j];
        }
    }
}

void fast_pow(int n, int m)
{
    while(n){
        if(n&1) multiple(f, resMatrix, m);
        multiple(f, f, m);
        n/=2;
    }
}

int main()
{
    int n, m;
    long long res;
    while(~scanf("%d%d", &n, &m)){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld", &f[i][j]);
                resMatrix[i][j] = f[i][j];
            }
        }
        fast_pow(n-2, m);
        res = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                res = res > resMatrix[i][j] ? res : resMatrix[i][j];
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}