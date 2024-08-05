#include<stdio.h>
int main(){
    int a, b;
    while(~scanf("%d%d",&a,&b)){
        printf("%d %d\n",a*b-a-b,(a-1)*(b-1)/2);
    }
    return 0;
}