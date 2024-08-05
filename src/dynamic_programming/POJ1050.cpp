#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace::std;

int arr[200][200] = {0};
int dp[200] = {0};
int mapping_array[200] = {0};
int res = -99999;

void sequence_dp(int n)
{
    dp[0] = max(0, mapping_array[0]);
    res = max(res, dp[0]);
    for(int i=1;i<n;i++){
        dp[i] = max(0, dp[i-1]) + mapping_array[i];
        res = max(res, dp[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &arr[i][j]);
    
    for(int i=0;i<n;i++){
        memset(mapping_array, 0, sizeof(mapping_array));
        for(int j=i;j<n;j++){
            for(int k=0;k<n;k++){
                mapping_array[k] += arr[j][k];
            }
            sequence_dp(n);
        }
        
    }
    printf("%d\n", res);
    return 0;
}