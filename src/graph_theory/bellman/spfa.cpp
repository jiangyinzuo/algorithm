#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
void spfa(int graph[303][303], int *dis, int start, int n)
{
    bool visited[303] = {false};
    memset(dis, 0x3f3f3f, sizeof(dis));
    queue<int> que;
    
    visited[start] = false;
    for(int i=1;i<=n;i++){
        if(i!=start){
            que.push(i);
            dis[i] = graph[start][i];
            visited[i] = true;
        }
    }
    while(!que.empty()){
        int vertex = que.front();
        que.pop();
        visited[vertex] = false;
        for(int i=1;i<=n;++i){
            if(dis[i] > dis[vertex] + graph[vertex][i]){
                dis[i] = dis[vertex] + graph[vertex][i];
                if(!visited[i]){
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
    }
}
int main()
{
    int n;
    while(~scanf("%d", &n)){
        int graph[303][303];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &graph[i][j]);
            }
        }
        int dis[303];
        spfa(graph, dis, 1, n);
        int res = dis[n];
        int c1 = dis[1];
        spfa(graph, dis, n, n);
        int c2 = dis[n];
        printf("%d\n", res<c1+c2?res:c1+c2);
    }
    return 0;
}