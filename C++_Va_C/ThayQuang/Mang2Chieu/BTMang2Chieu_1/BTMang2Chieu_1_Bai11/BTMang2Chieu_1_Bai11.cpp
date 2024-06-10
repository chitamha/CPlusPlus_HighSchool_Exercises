#include <iostream>
using namespace std;
int A[500][500];
int B[500];
int cow, col;
int sum=0, demhang, m;
int main(){
    freopen("ROWMAX.INP", "r", stdin);
    freopen("ROWMAX.OUT", "w", stdout);
    cin>> cow>> col;
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cin>> A[i][j];
        }
    }
    /*
    cout<< "Xuat mang"<< endl;
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
    */
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            sum+=A[i][j];
        }
        B[i]=sum;
        sum=0;
        m=B[0];
        if (m<=B[i]){
                m=B[i];
            }
    }
    cout<< m<< endl;
    for (int i=0; i<cow; i++){
        if (B[i]==m){
            cout<< i+1<< " ";
        }
    }
}
