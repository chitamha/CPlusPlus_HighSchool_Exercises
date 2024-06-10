#include <iostream>
using namespace std;
int n;
int main(){
    int sum=0;
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
        sum+=A[i][i]+A[i][n-1-i];
    }
    cout<< sum;
    return 0;
}
