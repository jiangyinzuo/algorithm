#include<cstdio>

long long dp[501][501] = {0};
int main()
{
    int n=500;
    for(int i=0;i<n;i++){
        dp[0][i] = 1;
        for(int j=i/2+1;j<=i;j++){
            dp[i][j] = 1;
        }
    }
    
    for(int i=2;i<n;i++){
        for(int j=i/2;j>=1;j--){
            dp[i][j] = dp[i][j+1] + dp[i-2*j][j];
        }
    }
    while(~scanf("%d", &n) && n!=0){
        printf("%d %lld\n", n, dp[n][1]);
    }
    return 0;
}