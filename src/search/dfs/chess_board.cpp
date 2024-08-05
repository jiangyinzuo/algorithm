#include<cstdio>
#include<cstring>
char chessBoard[10][10];
bool visited[10][10];
long long ans;
int n, k;
bool isOk(int i, int j)
{
    for(int k=0;k<n;k++){
        if(visited[k][j] && k!=i) return false;
    }
    return true;
}
void dfs(int level, int start_row)
{
    if(level == k) {
        ans++;
        return;
    }
    int m=0;
    bool flag=true;
    for(int i=start_row;i<=level+n-k+m;++i){
        for(int j=0;j<n;++j){
            if(chessBoard[i][j] == '#' && !visited[i][j] && isOk(i, j)){
                flag = false;
                visited[i][j] = true;
                dfs(level+1, i+1);
                visited[i][j] = false;
            }
        }
        if(flag && i<n) {m++;flag=true;}
    }
}
int main()
{
    while(scanf("%d %d", &n, &k) && n!=-1 && k!=-1){
        for(int i=0;i<n;i++)
            scanf("%s", chessBoard[i]);
        ans = 0;
        std::memset(visited, false, sizeof(visited));
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}