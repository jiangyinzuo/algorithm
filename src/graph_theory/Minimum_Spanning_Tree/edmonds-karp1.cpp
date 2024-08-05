#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

bool bfs(int v, int capacity[16][16], int pre[16])
{
    bool visited[16] = {true, true, false};
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int vertex = que.front();
        que.pop();
        if(vertex == v) {
            return true;
        }
        for(int i=1;i<=v;++i){
            if(!visited[i] && capacity[vertex][i] > 0){
                que.push(i);
                visited[i] = true;
                pre[i] = vertex;
            }
        }
    }
    return false;
}

int edmonds_karp(int v, int capacity[16][16])
{
    int max_flow = 0;
    int pre[16];
    while(bfs(v, capacity, pre)){
        int min_weight = 999999;
        int vertex = v;
        while(vertex != 1){
            if(capacity[pre[vertex]][vertex] < min_weight){
                min_weight = capacity[pre[vertex]][vertex];
            }
            vertex = pre[vertex];
        }
        vertex = v;
        while(vertex != 1){
            capacity[pre[vertex]][vertex] -= min_weight;
            capacity[vertex][pre[vertex]] += min_weight;
            vertex = pre[vertex];
        }
        max_flow += min_weight;
    }
    return max_flow;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int kase=1;kase<=t;++kase){
        int capacity[16][16] = {0};
        int v, e;
        int v1, v2, cap;
        scanf("%d %d", &v, &e);
        for(int i=0;i<e;++i){
            scanf("%d %d %d", &v1, &v2, &cap);
            capacity[v1][v2] += cap;
        }
        printf("Case %d: %d\n", kase, edmonds_karp(v, capacity));
    }
    return 0;
}