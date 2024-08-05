#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef struct PrimePath{
    int number;
    int step;
} PrimePath;

bool is_prime[10001];

void sieve()
{
    for(int i=2;i<=9999;++i){
        is_prime[i] = true;
    }
    for(int i=2;i<=9999;++i){
        if(is_prime[i]){
            for(int j=2;i*j<=9999;++j){
                is_prime[i*j] = false;
            }
        }
    }
}

void bfs(int start_prime, int end_prime)
{
    queue<PrimePath> que;
    bool visited[10001] = {false};
    PrimePath start = {start_prime, 0};
    que.push(start);
    visited[start_prime] = true;
    while(!que.empty()){
        PrimePath curPrime = que.front();
        que.pop();
        if(curPrime.number == end_prime){
            printf("%d\n", curPrime.step);
            return;
        }
        for(int i=1;i<=9;i+=2){
            int num = curPrime.number / 10 * 10 + i;
            if(is_prime[num] && !visited[num]){
                PrimePath n = {num, curPrime.step+1};
                que.push(n);
                visited[num] = true;
            }
        }
        for(int i=0;i<=9;i++){
            int num = curPrime.number / 100 *100 + i*10 + curPrime.number%10;
            if(is_prime[num] && !visited[num]){
                PrimePath n = {num, curPrime.step+1};
                que.push(n);
                visited[num] = true;
            }
        }
        for(int i=0;i<=9;i++){
            int num = curPrime.number / 1000 *1000 + i*100 + curPrime.number%100;
            if(is_prime[num] && !visited[num]){
                PrimePath n = {num, curPrime.step+1};
                que.push(n);
                visited[num] = true;
            }
        }
        for(int i=1;i<=9;i++){
            int num = i*1000 + curPrime.number%1000;
            if(is_prime[num] && !visited[num]){
                PrimePath n = {num, curPrime.step+1};
                que.push(n);
                visited[num] = true;
            }
        }
    }
}

int main()
{
    int t;
    int start_prime, end_prime;
    sieve();
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &start_prime, &end_prime);
        bfs(start_prime, end_prime);
    }
    return 0;
}