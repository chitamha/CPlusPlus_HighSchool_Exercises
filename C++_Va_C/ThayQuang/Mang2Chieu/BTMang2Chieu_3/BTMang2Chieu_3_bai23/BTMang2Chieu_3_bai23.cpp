#include <iostream>
using namespace std;
int out(int A[][251]){
    int dem=0;
    for (int i=0; i<251; i++){
        for (int j=0; j<251; j++){
            if (A[i][j]==0 && A[i+1][j]==1 && A[i][j+1]==1){
                dem+=1;
            }
        }
    }
    return dem;
}
int A[251][251];
int main(){
    freopen("RECT.INP", "r", stdin);
    freopen("RECT.OUT", "w", stdout);
    int n;
    cin>> n;
    for (int i=0; i<251; i++){
        for (int j=0; j<251; j++){
            A[i][j]=1;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    cout<< out(A);
}
