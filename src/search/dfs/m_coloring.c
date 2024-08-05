#include <stdio.h>

int map[500][500] = {0};
int vertex_color[500] = {0};
int color = 1;
int flag = 0;

int is_ok(int v, int vertex)
{
    for (int i=1; i<=v; ++i) {
        if (map[i][vertex] && vertex_color[i] == vertex_color[vertex]) {
            return 0;
        }
    }

    return 1;
}

void m_coloring(int v, int level)
{
    if (level > v) {
        flag = 1;
        return;
    }

    for (int i=1; i<=color && !flag; ++i) {
        vertex_color[level] = i;
        if (is_ok(v, level)) {
            m_coloring(v, level+1);
        }
    }

    if (!flag) {
        vertex_color[level] = ++color;
        m_coloring(v, level+1);
    }
}

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);

    int v1, v2, w;
    for (int i=0; i<e; ++i) {
        scanf("%d %d", &v1, &v2);
        map[v1][v2] = map[v2][v1] = 1;
    }

    m_coloring(v, 1);
    for (int i=1; i<=v; ++i) {
        printf("%d ", vertex_color[i]);
    }
    printf("\n%d\n", color);

    return 0;
}