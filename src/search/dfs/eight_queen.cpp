#include<iostream>
using namespace std;

int chessBoard[8][8] = {0};
int count = 0;

bool isOk(int row, int col)
{
    int j=1;
    for(int i=row-1;i>=0;i--){
        if( chessBoard[i][col] == 1 ||
            (col-j >=0 && chessBoard[i][col-j] == 1) ||
            (col+j <8 && chessBoard[i][col+j] == 1) ){
                return false;
            }
        j++;
    }
    return true;
}

void trackBack(int row, int num)
{
    if(row == num){
        count++;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout << chessBoard[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "---------" << endl;
        return;
    }
    for(int col=0;col<num;col++){
        chessBoard[row][col] = 1;
        if(isOk(row, col)) {
            trackBack(row+1, num);
        }
        chessBoard[row][col] = 0;
    }
}


int main()
{
    trackBack(0, 8);
    cout << count << " solutions" << endl;
    return 0;
}