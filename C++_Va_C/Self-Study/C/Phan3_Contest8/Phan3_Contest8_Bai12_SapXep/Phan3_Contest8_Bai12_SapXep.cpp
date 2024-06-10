#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n][n], B[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
            B[j][i]=A[i][j];
        }
    }
    for (int i=0; i<n; i++){
        sort(B[i], B[i]+n);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< B[j][i]<< " ";
        }
        cout<< endl;
    }
}
