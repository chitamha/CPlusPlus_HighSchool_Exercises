#include <iostream>
using namespace std;
int cow1, col1, k;
int arr1[1000][1000];
int main(){
    cin>> cow1>> col1;
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cin>> arr1[i][j];
        }
    }
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cout<< arr1[i][j]<< "\t";
        }
        cout<< endl;
    }
    int x;
    cin>> x;
    int kk=0;
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            if (arr1[i][j]==x) {
                cout<< "Dong "<< i+1<< " cot "<< j+1;
                kk=1;
                break;
            }
        }
        if (kk==1) break;
    }
    if (kk==0) cout<< "Khong tim thay phan tu "<< x;
}
