#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

const int MAX_VERTEX_NUM = 26;
static int in_deg[MAX_VERTEX_NUM];
static bool graph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

const int NOT_SORTED = 2;
const int HAS_CIRCLE = 0;
const int SORTED = 1;

/**
 * 拓扑排序判断一组字符的顺序。维护in_deg数组，记录每个点的入度。
 * 将所有入度为0的点入队，出队时更新以该点为前驱的入度，若有新的点入度为0，则入队。
 * 有环：队列为空后，仍然有点未加入结果向量。
 * 不能确定排序：过程中队列长度大于1
 * 全序：结果向量长度 = 图中点的数量
 * @return
 */
int topo_sort(int n, std::vector<int> &result) {
    std::queue<int> start_q;
    int temp_in_deg[MAX_VERTEX_NUM];
    for (int i = 0; i < n; ++i) {
        if ((temp_in_deg[i] = in_deg[i]) == 0) start_q.push(i);
    }

    bool not_sorted = false;
    while (!start_q.empty()) {
        if (start_q.size() > 1) not_sorted = true;
        int start = start_q.front();
        result.push_back(start);
        start_q.pop();
        for (int i = 0; i < n; ++i) {
            if (graph[start][i])
                if (--temp_in_deg[i] == 0) start_q.push(i);
        }
    }

    if (result.size() < n) return HAS_CIRCLE;
    return not_sorted ? NOT_SORTED : SORTED;
}

int main() {
    int n, m;
    char rel[4];
    while (scanf("%d %d", &n, &m) && n + m) {
        memset(in_deg, 0, sizeof(in_deg));
        memset(graph, false, sizeof(graph));

        int res;
        bool not_end = true;
        int edge_id = -1;
        std::vector<int> result;
        for (int i = 0; i < m; ++i) {
            scanf("%s", rel);
            if (not_end && !graph[rel[0] - 'A'][rel[2] - 'A']) {
                in_deg[rel[2] - 'A']++;
                graph[rel[0] - 'A'][rel[2] - 'A'] = true;
                result.clear();
                res = topo_sort(n, result);
                if (res == HAS_CIRCLE || res == SORTED) {
                    not_end = false;
                    edge_id = i + 1;
                }
            }
        }
        if (res == HAS_CIRCLE) {
            printf("Inconsistency found after %d relations.\n", edge_id);
        } else if (res == NOT_SORTED) {
            printf("Sorted sequence cannot be determined.\n");
        } else {
            printf("Sorted sequence determined after %d relations: ", edge_id);
            for (int i = 0; i < result.size(); ++i) {
                printf("%c", result[i] + 'A');
            }
            printf(".\n");
        }
    }
    return 0;
}