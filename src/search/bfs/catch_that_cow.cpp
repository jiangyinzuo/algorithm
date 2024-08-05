#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int s, e;
bool visited[100002] = {false};
struct Step{
    int location;
    int count;
};
queue<Step> q;
void bfs()
{
    Step step;
    step.location = s;
    step.count = 0;
    
    q.push(step);
    visited[step.location] = true;
    while(!q.empty()){
        step = q.front();
        q.pop();
        if(step.location == e) {printf("%d\n", step.count); return;}
        
        ++step.count;
        if (step.location > e) {
            --step.location;
            q.push(step);
            continue;
        }
        ++step.location;
        if(step.location <= 100000 && !visited[step.location]){
            q.push(step);
            visited[step.location] = true;
        }
        
        step.location-=2;
        if(step.location>0 && !visited[step.location]){
            q.push(step);
            visited[step.location] = true;
        }

        step.location = (step.location + 1)*2;
        if(step.location > 0 && step.location <= 100000 && !visited[step.location]){
            q.push(step);
            visited[step.location] = true;
        }
            
    }
}

int main()
{
    while(~scanf("%d %d", &s, &e)){
        memset(visited, 0, sizeof(visited));
        while(!q.empty()) q.pop();
        if(e<=s) printf("%d\n", s-e);
        else bfs();
    }

    return 0;
}