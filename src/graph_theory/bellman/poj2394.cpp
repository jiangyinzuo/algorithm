#include <cstdio>
#define MAX_DIS 700009
using namespace std;

struct Edge {
    int v1;
    int v2;
    int weight;
} edges[1004]; // bidirectional edge

int min_dis[1004];

void bellman_ford(int edge_total, int vertex_total)
{
    for (int i = 1; i <= vertex_total - 1; ++i) {
        for (int j = 0; j < edge_total; ++j) {

            // printf("bellman: %d %d %d\n", min_dis[edges[j].v1], min_dis[edges[j].v2], edges[j].weight);
            // because of bidirectional edge, do relaxation twice
            if (min_dis[edges[j].v1] > min_dis[edges[j].v2] + edges[j].weight) {
                min_dis[edges[j].v1] = min_dis[edges[j].v2] + edges[j].weight;
            }
            if (min_dis[edges[j].v2] > min_dis[edges[j].v1] + edges[j].weight) {
                min_dis[edges[j].v2] = min_dis[edges[j].v1] + edges[j].weight;
            }
        }
    }
}

int main()
{   
    int vertex, edge, cow_total, m;
    scanf("%d %d %d %d", &vertex, &edge, &cow_total, &m);
    for (int i = 0; i < edge; ++i) {
        scanf("%d %d %d", &edges[i].v1, &edges[i].v2, &edges[i].weight);  
    }

    min_dis[1] = 0;
    for (int i = 2; i <= vertex; ++i) {
        min_dis[i] = MAX_DIS;
    }
    bellman_ford(edge, vertex);

    int cow_vertex;
    int guilty_cows[505];
    int idx = 0;
    for (int j = 1; j <= cow_total; ++j) {
        scanf("%d", &cow_vertex);
        if (min_dis[cow_vertex] <= m) {
            guilty_cows[idx++] = j;
        }
    }
    printf("%d\n", idx);
    for (int i = 0; i < idx; ++i) {
        printf("%d\n", guilty_cows[i]);
    }

    // for(int i = 1; i <= vertex; ++i) {
    //     printf("min_dis: %d\n", min_dis[i]);
    // }

    return 0;
}