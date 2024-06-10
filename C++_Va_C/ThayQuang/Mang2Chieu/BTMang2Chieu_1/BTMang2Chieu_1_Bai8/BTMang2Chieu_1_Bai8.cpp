#include <iostream>
#include <math.h>
using namespace std;
int cow1, col1;
int arr1[1000][1000];
int main(){
    cin>> cow1>> col1;
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cin>> arr1[i][j];
        }
    }
    /*
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cout<< arr1[i][j]<< "\t";
        }
        cout<< endl;
    }
    */
    int k;
    cout<< "Nhap x="; cin>> k;
    int dem=0;
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            if (arr1[i][j]==k){
                dem+=1;
            }
        }
    }
    if (dem>=1) cout<< "so "<<k << " xuat hien "<< dem<< " lan";
    else cout<< "Khong xuat hien";
}
