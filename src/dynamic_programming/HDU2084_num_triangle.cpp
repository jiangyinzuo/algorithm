#include<iostream>
using namespace std;
int array[109][109];
int main()
{
    int testCase, layer;
    cin >> testCase;
    while(testCase--){
        cin >> layer;
        for(int i=0;i<layer;i++){
            for(int j=0;j<=i;j++){
                cin >> array[i][j];
            }
        }

        for(int i=layer-1;i>=1;i--){
            for(int j=1;j<=i;j++){
                array[i-1][j-1] += array[i][j-1]>array[i][j]?array[i][j-1]:array[i][j];
            }
        }

        cout << array[0][0] << endl;
    }
    return 0;
}