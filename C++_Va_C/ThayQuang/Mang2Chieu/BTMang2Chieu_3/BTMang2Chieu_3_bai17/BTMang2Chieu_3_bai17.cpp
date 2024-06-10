#include <iostream>
using namespace std;
int A[1000][1000]={0};

void out(int m, int n, int A[][1000]){
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (A[i][j]<=A[i+1][j] && A[i][j]<=A[i-1][j] && A[i][j]<=A[i][j+1] && A[i][j]<=A[i][j-1]){
                    cout<< "("<< i+1<< ","<< j+1<< ")"<< endl;
                }
            }
        }
}

int main(){
    freopen("FIND.INP", "r", stdin);
    freopen("FIND.OUT", "w", stdout);
    int m, n;
    cin>> m>> n;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    out(m, n, A);
}
