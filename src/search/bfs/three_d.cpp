#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef struct {
    int x; int y; int z;
} Point;
int borderX, borderY, borderZ;
queue<Point> q;
char graph[31][31][31]; //z x y
int dis[31][31][31];
bool visited[31][31][31];
int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0},
                 {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
bool isOk(int x, int y, int z, int distance)
{
    if( 0<=z&& z<borderZ
        &&0<=x&& x<borderX
        &&0<=y&& y<borderY
        && graph[z][x][y]!='#' && !visited[z][x][y]){
        visited[z][x][y] = true;
        dis[z][x][y] = distance + 1;
        return true;
    }
    return false;
}
bool bfs()
{
    Point curP, temp;
    while(!q.empty()){
        curP = q.front();
        q.pop();
        if(graph[curP.z][curP.x][curP.y] == 'E'){
            printf("Escaped in %d minute(s).\n", dis[curP.z][curP.x][curP.y]);
            return true;
        }
        for(int i=0;i<6;++i){
            if(isOk(curP.x+dir[i][0], curP.y+dir[i][1],
            curP.z+dir[i][2], dis[curP.z][curP.x][curP.y])){
                temp.x = curP.x+dir[i][0];
                temp.y = curP.y+dir[i][1];
                temp.z = curP.z+dir[i][2];
                q.push(temp);
            }
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d %d %d", &borderZ, &borderX, &borderY) && borderX && borderY && borderZ){
        memset(dis, 0, sizeof(dis));
        memset(visited, false, sizeof(visited));
        while(!q.empty()) q.pop();
        for(int k=0;k<borderZ;k++)
            for(int i=0;i<borderX;i++)
                    scanf("%s", graph[k][i]);

        for(int k=0;k<borderZ;k++){
            for(int i=0;i<borderX;i++){
                for(int j=0;j<borderY;j++){
                    if(graph[k][i][j] == 'S'){
                        Point p;
                        p.x = i;
                        p.y = j;
                        p.z = k;
                        q.push(p);
                        dis[k][i][j] = 0;
                    }
                }
            }
        }
        if(!bfs()) printf("Trapped!\n");
    }
    return 0;
}