#include<cstdio>
#include<cstring>
int array[100002][13];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int numOfCake, time, location, endTime = 0, res;
    while(1){
        scanf("%d",&numOfCake);
        if(numOfCake == 0){
            break;
        }
        memset(array, 0, sizeof(array));
        while(numOfCake--){
            scanf("%d%d",&location, &time);
            array[time][location]++;
            endTime = endTime > time ? endTime : time;
        }
        for(int i=endTime;i>=1;i--){
            array[i-1][0] += max(array[i][0], array[i][1]);
            for(int j=1;j<=9;j++){
                array[i-1][j] += max(array[i][j-1], max(array[i][j], array[i][j+1]));
            }
            array[i-1][10] += max(array[i][9], array[i][10]);
        }
        printf("%d\n",array[0][5]);
    }
    return 0;
}
