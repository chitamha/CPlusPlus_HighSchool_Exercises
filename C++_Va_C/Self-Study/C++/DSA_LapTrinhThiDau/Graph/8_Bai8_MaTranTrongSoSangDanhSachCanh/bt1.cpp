#include <bits/stdc++.h>
using namespace std;

int A[1005][1005];
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
            if (A[i][j]!=0 && j>i){
                cout<< i<< ' '<< j<< ' '<< A[i][j]<< endl;
            }
        }
    }
    return 0;
}
