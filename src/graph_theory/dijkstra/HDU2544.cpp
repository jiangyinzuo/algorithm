#include<cstdio>
#include<cstring>
using namespace std;

int graph[102][102];
bool visited[102];
int distance[102];
const int inf = 1<<30;

int min(int a, int b)
{
    return a<b ? a : b;
}

void dijkstra(int numOfVertex)
{
    distance[1] = 0;
    for(int i=2;i<=numOfVertex;i++){
        distance[i] = inf;
    }
    for(int i=1;i<=numOfVertex;i++){
        int minDistance = inf, minVertex;
        for(int j=1;j<=numOfVertex;j++){
            if(distance[j] < minDistance&&!visited[j]){
                minVertex = j;
                minDistance = distance[j];
            }
        }
        visited[minVertex] = true;
        for(int j=1;j<=numOfVertex;j++){
            if(!visited[j])
                distance[j] = min(distance[j], distance[minVertex]+graph[minVertex][j]);
        }
    }
}

int main()
{
    int numOfEdge, numOfVertex, v1, v2, temp;
    while(1){
        scanf("%d %d", &numOfVertex, &numOfEdge);
        if(numOfEdge == 0 && numOfVertex == 0) break;
        for(int i=1;i<=numOfVertex;i++)
            for(int j=1;j<=numOfVertex;j++){
            graph[i][j] = inf;
        }
        memset(visited, false, sizeof(visited));

        for(int i=0;i<numOfEdge;i++){
            scanf("%d %d", &v1, &v2);
            scanf("%d", &temp);
            if(graph[v1][v2] == 0 || temp < graph[v1][v2])
                graph[v2][v1] = graph[v1][v2] = temp;
        }
        dijkstra(numOfVertex);
        printf("%d\n",distance[numOfVertex]);
    }
    return 0;
}