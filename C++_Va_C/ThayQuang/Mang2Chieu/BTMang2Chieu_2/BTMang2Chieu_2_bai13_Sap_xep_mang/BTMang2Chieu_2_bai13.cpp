#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int main(){
    cin>> n>> m;
    int A[n][m], B[m*n], cnt=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
            B[cnt]=A[i][j];
            cnt++;
        }
    }
    sort(B, B+cnt);
    cnt=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            A[i][j]=B[cnt];
            ++cnt;
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}
