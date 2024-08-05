#include<cstdio>
unsigned short int dp[2][5003] = {0};
int main()
{
    int n;
    char s[5003];
    scanf("%d%s", &n, s);
    for(int i=n-1;i>=0;--i)
        for(int j=i;j<n;++j)
            if(s[i] == s[j]) dp[i&1][j] = dp[(i+1)&1][j-1];
            else dp[i&1][j] = 1 + (dp[(i+1)&1][j] < dp[i&1][j-1] ? dp[(i+1)&1][j] : dp[i&1][j-1]);
    printf("%d\n", dp[0][n-1]);
    return 0;
}