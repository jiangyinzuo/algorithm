#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
typedef struct {
    int x;
    int y;
}Point;
int maze[5][5];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

queue<Point> que;
stack<Point> sta;
void dfs(int x, int y, int dis)
{
    if(x == 0 && y == 0 && dis == 1){
        printf("(0, 0)\n");
        while(sta.size() > 1){
            printf("(%d, %d)\n", sta.top().x, sta.top().y);
            sta.pop();
        }
    }
    for(int i=0;i<4;i++){
        if(0<=x + dir[i][0] && x+dir[i][0] < 5
        && 0<=y+dir[i][1] && y+dir[i][1] < 5 &&
        maze[x+dir[i][0]][y+dir[i][1]] == dis-1){
            Point p;
            p.x = x;
            p.y = y;
            sta.push(p);
            dfs(x + dir[i][0], y+dir[i][1], dis-1);
        }
    }
}
void isOk(int x, int y, int dis)
{
    if(0<=x && x < 5 && 0<=y && y < 5 && maze[x][y] == 0){
        maze[x][y] = dis+1;
        Point p;
        p.x = x;
        p.y = y;
        que.push(p);
    }
}
void bfs()
{
    maze[0][0] = 1;
    Point p;
    p.x = 0;
    p.y = 0;
    que.push(p);
    while (!que.empty()){
        p = que.front();
        que.pop();
        for(int i=0;i<4;i++){
            isOk(p.x + dir[i][0], p.y + dir[i][1], maze[p.x][p.y]);
            if(p.x + dir[i][0] == 4 && p.y + dir[i][1] == 4){
                Point p;
                p.x = 4;
                p.y = 4;
                sta.push(p);
                dfs(4, 4, maze[4][4]);
                return;
            }
        }
    }
    
}
int main()
{
    int temp;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d", &temp);
            if(temp == 1){
                maze[i][j] = -1;
            }
            else {
                maze[i][j] = 0;
            }
        }
    }
    bfs();
    return 0;
}