#include<stdio.h>
struct Edge{
    int v1;
    int v2;
    double rate;
    double commission;
}Edge[222];
void bellman(int v, int e, double c, int startVertex)
{
    double capital[111] = {0};
    capital[startVertex] = c;
    int count=0;
    for(int i=0;i<=v;i++){
        int flag = 0;
        for(int j=0;j<e;j++){
            if(capital[Edge[j].v2] < (capital[Edge[j].v1] - Edge[j].commission) * Edge[j].rate){
                capital[Edge[j].v2] = (capital[Edge[j].v1] - Edge[j].commission) * Edge[j].rate;
                flag = 1;
            }
        }
        if(!flag) {
            break;
        }
    }
    for(int j=0;j<e;j++){
        if(capital[Edge[j].v2] < (capital[Edge[j].v1] - Edge[j].commission) * Edge[j].rate){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
int main()
{
    int e, v, startVertex;
    double c;
    while(~scanf("%d %d %d %lf", &v, &e, &startVertex, &c)){
        int j = 0;
        for(int i=0;i<e;i++){
            int ea, eb;
            double rab, rba, cab, cba;
            scanf("%d %d %lf %lf %lf %lf", &ea, &eb, &rab, &cab, &rba, &cba);
            Edge[j].v1 = ea;
            Edge[j].v2 = eb;
            Edge[j].rate = rab;
            Edge[j++].commission = cab;
            Edge[j].v1 = eb;
            Edge[j].v2 = ea;
            Edge[j].rate = rba;
            Edge[j++].commission = cba; 
        }
        bellman(v, 2*e, c, startVertex);
    }
    return 0;
}