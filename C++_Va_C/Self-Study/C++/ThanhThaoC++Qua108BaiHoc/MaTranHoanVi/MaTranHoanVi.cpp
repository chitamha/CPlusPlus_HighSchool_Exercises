#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int cow, col;
int main(){
    cout<< "Moi ban nhap so hang va cot: "; cin>> cow>> col;
    int a[cow][col];
    srand(time(NULL));
    //Nhap ma tran
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            a[i][j]=rand()%100;
        }
    }
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cout<< a[i][j]<< "\t";
        }
        cout<< endl;
    }
    int b[col][cow];
    cout<< "Sau khi hoan doi la"<< endl;
    for (int i=0; i<col; i++){
        for (int j=0; j<cow; j++){
            b[i][j]=a[j][i];
            cout<< b[i][j]<< "\t";
        }
        cout<< endl;
    }
}
