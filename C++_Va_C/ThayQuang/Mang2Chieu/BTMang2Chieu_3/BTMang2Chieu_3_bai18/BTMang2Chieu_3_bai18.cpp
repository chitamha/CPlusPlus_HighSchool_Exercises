#include <iostream>
using namespace std;
int n;
int main(){
    freopen("CLOCK.INP", "r", stdin);
    freopen("CLOCK.OUT", "w", stdout);
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    int dem=0;
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){
            if (A[i][j]<A[i][j+1] && A[i][j+1]<A[i+1][j+1] && A[i+1][j+1]<A[i+1][j]){
                dem++;
            }
        }
    }
    cout<< dem;
}
