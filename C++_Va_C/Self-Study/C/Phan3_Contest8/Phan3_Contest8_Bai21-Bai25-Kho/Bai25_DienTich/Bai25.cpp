#include <iostream>
using namespace std;
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};
int dem=0;
int A[505][505];
int n, m;
void loang(int i, int j){
    if (A[i][j]==1) dem+=1;
    A[i][j]=0;
    for (int k=0; k<4; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=0 && i1<n && j1>=0 && j1<m && A[i1][j1]==1){
            loang(i1, j1);
        }
    }
}
int main(){
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin>> n>> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> A[i][j];
        }
    }
    int Max=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            dem=0;
            loang(i, j);
            Max=max(Max, dem);
        }
    }
    cout<< Max;
}
