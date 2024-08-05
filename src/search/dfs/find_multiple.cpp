#include<cstdio>
bool done;
void dfs(long long multiple, int n, int level)
{
    if(done || level > 18) return;
    
    if(multiple % n == 0) {
        printf("%lld\n" ,multiple);
        done = true;
        return;
    }
    else {
        dfs(multiple*10, n, level+1);
        dfs(multiple*10+1, n, level+1);
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) && n){
        done = false;
        dfs(1, n, 0);
    }
    return 0;
}