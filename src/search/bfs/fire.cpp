#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

char graph[1004][1004];
bool visited[1004][1004];
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int g_x, g_y;

struct Point{
    int x;
    int y;
    int level;
    Point(int x, int y, int level):x(x), y(y), level(level){}
};
queue<Point> que_j, que_f;
int isOk(int x, int y, int level)
{
    if(x<0 || x >= g_x || y<0 || y>=g_y){
        printf("%d\n", level+1);
        return -1;
    }
    if( (graph[x][y] != '.'&& graph[x][y] !='J') || visited[x][y]) return 0;
    else {
        visited[x][y] = true;
        graph[x][y] = 'J';
        Point temp(x, y, level+1);
        que_j.push(temp);
        return 1;
    }
}
void fire(int x, int y, int level)
{
    if(0<=x && x < g_x && 0<=y && y<g_y &&(graph[x][y] == '.' || graph[x][y] == 'J') ){
        graph[x][y] = 'F';
        Point p(x, y, level+1);
        que_f.push(p);
    }
}
void bfs(int j_x, int j_y)
{
    Point temp(j_x, j_y, 0);
    que_j.push(temp);
    int level = 0;
    int res;
    int fireLevel;
    Point curF(0, 0, 0);
    while(!que_j.empty()){
        Point curP = que_j.front();
        que_j.pop();
        while(!que_f.empty()){
            curF = que_f.front();
            if(curF.level > curP.level){
                break;
            }
            que_f.pop();
            for(int i=0;i<4;i++){
                fire(curF.x + dir[i][0], curF.y + dir[i][1], curF.level);
            }
        }

        for(int i=0;i<4;i++){
            res = isOk(curP.x + dir[i][0], curP.y + dir[i][1], curP.level);
            if ( res == -1) return;
        }
        // for(int i=0;i<g_x;i++)
        //     printf("%s\n", graph[i]);
        //     printf("\n");
        
    }
    printf("IMPOSSIBLE\n");
}

int main()
{
    int n;
    int j_x, j_y;
    int f_x, f_y;
    scanf("%d", &n);
    while (n--){
        memset(visited, 0, sizeof(visited));
        while(!que_j.empty()) que_j.pop();
        while(!que_f.empty()) que_f.pop();
        scanf("%d %d", &g_x, &g_y);
        for(int i=0;i<g_x;i++){
            scanf("%s", graph[i]);
        }
        for(int i=0;i<g_x;i++){
            for(int j=0;j<g_y;j++){
                if(graph[i][j] == 'J') {
                    j_x = i;
                    j_y = j;
                    visited[i][j] == true;
                }
                if(graph[i][j] == 'F') {
                    f_x = i;
                    f_y = j;
                    Point f(f_x, f_y, 0);
                    que_f.push(f);
                }
            }
        }
        bfs(j_x, j_y);
    }
    
    return 0;
}