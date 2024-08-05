#include <cstdio>
#include <queue>
using namespace std;

int map[10001][10001] = {0};
int min_dis[10001];

void spfa(int vertex_total, int start_vertex)
{
   queue<int> que;
   que.push(start_vertex);

    while (!que.empty()) {
        int cur_vertex = que.front();
        que.pop();

        for (int i = 1; i <= vertex_total; ++i) {
            if (map[cur_vertex][i] != 0 && min_dis[cur_vertex] + map[cur_vertex][i] < min_dis[i]) {
                que.push(i);
                min_dis[i] = min_dis[cur_vertex] + map[cur_vertex][i];
            }
        }

    } 
}

int main()
{
    int vertex, edge, start_vertex;
    scanf("%d %d %d", &vertex, &edge, &start_vertex);

    int weight, v1, v2;
    for (int i = 0; i < edge; ++i) {
        scanf("%d %d %d", &v1, &v2, &weight);
        map[v1][v2] = weight;
    }
    for (int i = 0; i <= vertex; ++i) {
        min_dis[i] = 2147483647;
    }
    min_dis[start_vertex] = 0;

    spfa(vertex, start_vertex);
    printf("%d", min_dis[1]);
    for (int i = 2; i <= vertex; ++i) {
        printf(" %d", min_dis[i]);
    }
    printf("\n");
    return 0;
}