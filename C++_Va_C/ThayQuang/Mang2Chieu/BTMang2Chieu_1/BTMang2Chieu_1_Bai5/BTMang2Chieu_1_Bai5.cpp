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
    cin>> k;
    if (k>0&&k<=cow1){
    for (int i=0; i<col1; i++){
        if (arr1[k-1][i]%2==0){
            cout<< arr1[k-1][i]<< "\t";
        }
    }
    } else{
    cout<< "Ban nhap loi";
    }
}
