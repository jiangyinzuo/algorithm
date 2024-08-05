#include<cstdio>
#include<cstring>
using namespace std;
char graph[200][200];
bool visited[200][200];
int n, m, count;
void dfs(int x, int y)
{
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i != 0 || j != 0) && 0 <= x + i &&
				x + i < n && 0 <= y + j && y + j < m && graph[x + i][y + j] == '@'
				&& !visited[x + i][y + j]) {
				visited[x + i][y + j] = true;
				dfs(x + i, y + j);
			}
		}
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) && n && m) {
		count = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) scanf("%s", graph[i]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && graph[i][j] == '@') {
					count++;
					visited[i][j] = true;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}