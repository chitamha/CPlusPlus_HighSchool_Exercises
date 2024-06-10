#include <bits/stdc++.h>
using namespace std;
int n, m, dem=0;
int dx[]={-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1, -1, 1, -1, 0, 1};
int A[100][100];
bool check(int i, int j){
    for (int k=0; k<8; k++){
        int i1=i+dx[k]; int j1=j+dy[k];
        if (i1>=0 && i1<n && j1>=0 && j1<m){
            if(A[i][j]<=A[i1][j1]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin>> n>> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (check(i, j)){
                dem+=1;
            }
        }
    }
    cout<< dem;
    return 0;
}
