#include <iostream>
using namespace std;
int n;
int main(){
    freopen("PRINT.INP", "r", stdin);
    freopen("PRINT.OUT", "w", stdout);
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i%2==0) cout<< A[i][j]<< " ";
            else cout<< A[i][n-1-j]<< " ";
        }
    }
    return 0;
}
