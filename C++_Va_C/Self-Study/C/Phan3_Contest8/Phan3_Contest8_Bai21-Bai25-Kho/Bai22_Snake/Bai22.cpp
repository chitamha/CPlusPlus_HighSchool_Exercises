#include <iostream>
using namespace std;
int n;
int main(){
    cin>> n;
    int A[n][n], B[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    int h1=0, hn=n-1;
    while (h1<=hn){
        for (int j=0; j<n; j++){
            B[h1][j]=A[h1][j];
        }
        h1++;
        int cnt=0;
        for (int j=n-1; j>=0; j--){
            B[h1][cnt]=A[h1][j];
            cnt++;
        }
        h1++;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< B[i][j]<< " ";
        }
        cout<< endl;
    }
    return 0;
}
