#include<stdio.h>
#include<string.h>
void floyd(int graph[][504], int v)
{
    for(int k=1;k<=v;++k){
        for(int i=1;i<=v;++i){
            for(int j=1;j<=v;++j){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
            if(graph[i][i] < 0) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int v, e, hole;
        scanf("%d %d %d", &v, &e, &hole);
        int graph[504][504];
        memset(graph, 0x3f3f3f, sizeof(graph));
        for(int i=1;i<=v;++i) graph[i][i] = 0;
        int v1, v2, weight;
        for(int i=1;i<=e;++i){
            scanf("%d %d %d", &v1, &v2, &weight);
            if(weight < graph[v1][v2]){
                graph[v1][v2] = graph[v2][v1] = weight;
            }
        }
        for(int i=1;i<=hole;++i){
            scanf("%d %d %d", &v1, &v2, &weight);
            graph[v1][v2] = -weight;
        }
        floyd(graph, v);
    }
    return 0;
}