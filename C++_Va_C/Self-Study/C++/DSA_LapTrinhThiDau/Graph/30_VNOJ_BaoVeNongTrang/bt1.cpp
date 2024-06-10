#include <bits/stdc++.h>
#define maxn 705
using namespace std;

int n, m, cnt=0;
int A[maxn][maxn], visited[maxn][maxn];
int dx[]={-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1, -1, 1, -1, 0, 1};

void dfs1(int i, int j, int s){
    for (int k=0; k<8; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=1 && i1<=n && j1>=1 && j1<=m && A[i1][j1]<=A[i][j] && A[i1][j1]<s && visited[i1][j1]==0){
            visited[i1][j1]=1;
            dfs1(i1, j1, s);
        }
    }
}

void dfs2(int i, int j){
    for (int k=0; k<8; k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if (i1>=1 && i1<=n && j1>=1 && j1<=m && visited[i1][j1]==0){
            visited[i1][j1]=1;
            dfs2(i1, j1);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) cin>> A[i][j];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (visited[i][j]==0) dfs1(i, j, A[i][j]);
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (visited[i][j]==0){
                cnt++;
                visited[i][j]=1;
                dfs2(i, j);
            }
        }
    }
    cout<< cnt;
    return 0;
}
