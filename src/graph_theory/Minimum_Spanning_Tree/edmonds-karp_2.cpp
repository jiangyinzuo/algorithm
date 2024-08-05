#include<cstdio>
#include<queue>
using namespace std;

bool bfs(bool capacity[403][403], int pre[403], int food, int cow, int drink)
{
    queue<int> que;
    bool visited[403] = {true, false};
    que.push(0);
    while(!que.empty()){
        int vertex = que.front();
        que.pop();
        if(vertex == 401) {
            return true;
        }
        for(int i=1;i<=food;++i){
            if(!visited[i] && capacity[vertex][i]){
                que.push(i);
                pre[i] = vertex;
                visited[i] = true;
            }
        }
        for(int i=101;i<=100+cow;++i){
            if(!visited[i] && capacity[vertex][i]){
                que.push(i);
                pre[i] = vertex;
                visited[i] = true;
            }
        }
        for(int i=201;i<=200+cow;++i){
            if(!visited[i] && capacity[vertex][i]){
                que.push(i);
                pre[i] = vertex;
                visited[i] = true;
            }
        }
        for(int i=301;i<=300+drink;++i){
            if(!visited[i] && capacity[vertex][i]){
                que.push(i);
                pre[i] = vertex;
                visited[i] = true;
            }
        }
        if(!visited[401] && capacity[vertex][401]){
            que.push(401);
            pre[401] = vertex;
            visited[401] = true;
        }
    }
    return false;
}

void edmonds_karp(bool capacity[403][403], int food, int cow, int drink)
{
    int maximal_flow = 0;
    int pre[403];
    while(bfs(capacity, pre, food, cow, drink)){
        int vertex = 401; // sink
        while(vertex != 0){
            capacity[pre[vertex]][vertex] = false;
            capacity[vertex][pre[vertex]] = true;
            vertex = pre[vertex];
        }
        ++maximal_flow;
    }
    printf("%d\n", maximal_flow);
}

int main()
{
    int cow, food, drink;
    bool capacity[403][403] = {false};
    /*
        0: source
        1-100: food
        101-200: cow
        201-300: cow
        301-400: drink
        401: sink
    */
    scanf("%d %d %d", &cow, &food, &drink);
    for(int i=1;i<=food;i++){
        capacity[0][i] = true;
    }
    int foodLikes, drinkLikes;
    for(int i=1;i<=cow;++i){
        scanf("%d %d", &foodLikes, &drinkLikes);
        int num;
        for(int j=1;j<=foodLikes;++j){
            scanf("%d", &num);
            capacity[num][100+i] = true;
        }
        capacity[100+i][200+i] = true;
        for(int j=1;j<=drinkLikes;++j){
            scanf("%d", &num);
            capacity[200+i][300+num] = true;
        }
    }
    for(int i=301;i<=300+drink;++i){
        capacity[i][401] = true;
    }
    edmonds_karp(capacity, food, cow, drink);
    return 0;
}