#include<cstdio>
#include<stack>
using namespace std;

int graph[20][20];
stack<int> s1, s2;

int findOddPoint()
{
    int res = 0;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            res ^= graph[i][j];
        }
        if(res == 1) return i;
    }
    return 1;
}

void Hierholzer()
{
    int curVertex = s1.top();
    for(int i=1;i<=10;i++){
        if(graph[curVertex][i] > 0) {
            graph[i][curVertex] = graph[curVertex][i] -= 1;
            s1.push(i);
            Hierholzer();
        }
    }
    printf("%d ", curVertex);
    s1.pop();
} 

int main()
{
    int v, e;
    int row, col;
    FILE *fp;
    fp = fopen("Hierholzer.txt", "r");
    fscanf(fp, "%d %d", &v, &e);
    for(int i=0;i<e;i++){
        fscanf(fp, "%d %d", &row, &col);
        graph[row][col] = graph[col][row] += 1;
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    int start = findOddPoint();
    printf("start: %d\n", start);
    s1.push(start);
    Hierholzer();
    return 0;
}
