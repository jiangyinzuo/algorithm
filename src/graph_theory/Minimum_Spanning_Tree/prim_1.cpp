#include<cstdio>
#include<cmath>
using namespace std;
typedef struct {
    int x;
    int y;
} Point;
double dis(Point & p1, Point &p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}
void prim(bool selected[101], Point p[101], int n)
{
    selected[0] = true;
    double totalWeight = 0;
    for(int k=0;k<n-1;k++){
        bool flag = true;
        double minDis = 1000;
        int minPoint;
        for(int i=0;i<n;i++){
            if(selected[i]){
                for(int j=0;j<n;j++){
                    if(!selected[j]) {
                        double distance = dis(p[i], p[j]);
                        if( 10 <= distance && distance <= minDis) {
                            minDis = distance;
                            minPoint = j;
                            flag = false;
                        }
                    }
                }
            }
        }
        if(flag){
            printf("oh!\n");
            return;
        }
        selected[minPoint] = true;
        totalWeight += minDis;
    }
    printf("%.1lf\n", totalWeight * 100);
}

int main()
{
    int t;
    Point p[101];
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        bool selected[101] = {false};
        for(int i=0;i<n;i++){
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        prim(selected, p, n);
    }
    
    return 0;
}