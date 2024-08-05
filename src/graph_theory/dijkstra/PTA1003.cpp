#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int graph[505][505] = {0};
int dis[505];
int peo[505] = {0};
int peo_init[505] = {0};
int road[505] = {0};
bool visited[505] = {false};
struct cmp{
    bool operator()(int a, int b){
        if(dis[a] > dis[b]) return true;
        return false;
    }
};

priority_queue< int, vector<int>, cmp > que;
void dijkstra(int v, int startV, int endV)
{
    for(int i=0;i<505;i++){
        dis[i] = INF;
        graph[i][i] = 0;
    }
    dis[startV] = 0;
    que.push(startV);
    road[startV] = 1;
    peo[startV] = peo_init[startV];
    
    while(!que.empty()){
        int curV = que.top();
        que.pop();
        visited[curV] = true;
        for(int i=0;i<v;i++){
            if(!visited[i] && graph[i][curV]!=0 && i!=curV){
                if(dis[i] > dis[curV] + graph[i][curV]){
                    dis[i] = dis[curV] + graph[i][curV];
                    road[i] = road[curV];
                    peo[i] = peo[curV] + peo_init[i];
                    que.push(i);
                }
                else if(dis[i] == dis[curV] + graph[i][curV]){
                    road[i] += road[curV];
                    peo[i] = peo[i] > peo[curV] + peo_init[i] ? peo[i] : peo[curV] + peo_init[i];
                }
            }
        }
        
    }
}
int main()
{
    int v,e,startV, endV;
    int v1, v2, w;
    scanf("%d %d %d %d", &v, &e, &startV, &endV);
    
    for(int i=0;i<v;++i){
        scanf("%d", &peo_init[i]);
    }
    peo[startV] = peo_init[startV];
    for(int i=0;i<e;++i){
        scanf("%d %d %d", &v1, &v2, &w);
        graph[v1][v2] = graph[v2][v1] = w;
    }
    
    dijkstra(v, startV, endV);
    printf("%d %d\n", road[endV], peo[endV]);
    return 0;
}