#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct Point {
	int x;
	int y;
	int cost;
};
char graph[209][209];
int visited_y[209][209];
int visited_m[209][209];
int direction[4][2] = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
int n, m;
Point temp;
queue<Point> q_y, q_m;

void move(int cost, int x, int y, char person)
{
	if (x < 0 || x >= n || y < 0 || y >= m || graph[x][y] == '#') return;
	if (person == 'y' && visited_y[x][y]>0) return;
	if (person == 'm' && visited_m[x][y]>0) return;
	if (person == 'y') visited_y[x][y] = cost + 1;
	else visited_m[x][y] = cost + 1;
	temp.x = x; temp.y = y; temp.cost = cost + 1;
	if (person == 'y')q_y.push(temp);
	else q_m.push(temp);
}

void bfs(queue<Point> &q, char person)
{
	Point curP;
	while (!q.empty()) {
        curP = q.front();
        q.pop();
		for (int i = 0; i < 4; i++) {
			move(curP.cost, curP.x + direction[i][0], curP.y + direction[i][1], person);
		}
	}
}
int main()
{

	while (~scanf("%d %d", &n, &m)) {
		for (int i = 0; i < n; i++) {
			scanf("%s", graph[i]);
		}
		memset(visited_y, 0, sizeof(visited_y));
		memset(visited_m, 0, sizeof(visited_m));
		while (!q_m.empty()) q_m.pop();
		while (!q_y.empty()) q_y.pop();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp.x = i;
				temp.y = j;
				temp.cost = 0;
				if (graph[i][j] == 'Y') {
					q_y.push(temp);
					visited_y[i][j] = 1;
				}
				if (graph[i][j] == 'M') {
					q_m.push(temp);
					visited_m[i][j] = 1;
				}
                if (graph[i][j] == '@'){
                    visited_y[i][j] = visited_m[i][j] = -1;
                }
			}
		}
		bfs(q_m, 'm');
        bfs(q_y, 'y');
        int ans = 9999999;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(graph[i][j] == '@' && visited_m[i][j] + visited_y[i][j] < ans && visited_m[i][j] != -1 && visited_y[i][j] != -1)
                    ans = visited_m[i][j] + visited_y[i][j];
            }
        printf("%d\n", 11*ans);
	}
	return 0;
}
