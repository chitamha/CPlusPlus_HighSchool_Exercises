#include <bits/stdc++.h>
using namespace std;

int A[1005][1005];
set<int> B[1005];
int main(){
    int n;
    cin>> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> A[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (A[i][j]==1){
                cout<< i<< " "<< j<< endl;
                B[i].insert(j);
            }
        }
    }
    cout<< endl;
    for (int i=1; i<=n; i++){
        cout<< i<< " : ";
        for (int x:B[i])
            cout<< x<< " ";
        cout<< endl;
    }
    return 0;
}
