#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, b;
        scanf("%d %d", &n, &b);
        for(int i=0;i<9973;++i){
            if( ( ((b%9973)*i)%9973-n%9973)%9973 == 0){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}