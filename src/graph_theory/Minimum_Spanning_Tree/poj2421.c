#include<stdio.h>

#define INF 999999999

void prim(int n, int graph[100][100]) {
    unsigned short int selected[100] = {0};
    selected[0] = 1;
    int totalWeight = 0;
    for (int k = 0; k < n - 1; ++k) {
        int minWeight = INF;
        int vertex;
        for (int i = 0; i < n; ++i) {
            if (selected[i]) {
                for (int j = 0; j < n; ++j) {
                    if (!selected[j] && minWeight > graph[i][j]) {
                        minWeight = graph[i][j];
                        vertex = j;
                    }
                }
            }
        }
        totalWeight += minWeight;
        selected[vertex] = 1;
    }
    printf("%d\n", totalWeight);
}

int main() {
    int n;
    int graph[100][100];

    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &graph[i][j]);
        int q, v1, v2;
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d", &v1, &v2);
            graph[v1 - 1][v2 - 1] = graph[v2 - 1][v1 - 1] = 0;
        }
        prim(n, graph);
    }

    return 0;
}