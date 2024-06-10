#include <iostream>
using namespace std;
int n;
int main(){
    cin>> n;
    int A[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    int u, v;
    cin>> u>> v;
    --u;
    --v;
    for (int i=0; i<n; i++){
        int tmp=A[u][i];
        A[u][i]=A[v][i];
        A[v][i]=tmp;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<< endl;
    }
}
