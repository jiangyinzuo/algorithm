#include<iostream>
using namespace std;

int li[10];
bool choose[10];

void full_permutation(int level, int child)
{
    if(level -1 == child){
        for(int i=1;i<=child;i++){
            cout << li[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=child;i++){
        if(!choose[i]){
            li[level] = i;
            choose[i] = true;
            full_permutation(level+1, child);
            choose[i] = false;
        }
    }
}

int main()
{
    full_permutation(1, 4);
    return 0;
}