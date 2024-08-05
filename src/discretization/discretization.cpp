#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand(time(0));
    int arr[20], sortedArr[20];
    for(int i=0;i<20;i++){
        sortedArr[i] = arr[i] = rand();
        printf("%d ",arr[i]);
    }
    printf("\n");
    sort(sortedArr, sortedArr+20);
    int m = unique(sortedArr, sortedArr+20) - sortedArr;

    for(int i=0;i<20;i++){
        arr[i] = lower_bound(sortedArr, sortedArr+m, arr[i]) - sortedArr;
        printf("%d ", arr[i]);
    }
    return 0;
}
