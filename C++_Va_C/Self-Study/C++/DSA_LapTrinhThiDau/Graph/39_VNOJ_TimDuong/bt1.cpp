#include <bits/stdc++.h>
#define maxn 505
using namespace std;

int n;
int h[maxn][maxn], visited[maxn][maxn];
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void bfs(int x, int y, int d){
    visited[x][y]=1;
    for (int k=0; k<4; k++){
        int i=x+dx[k], j=y+dy[k];
        if (i>=1 && i<=n && j>=1 && j<=n && abs(h[i][j]-h[x][y])<=d && visited[i][j]==0){
            bfs(i, j, d);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin>> h[i][j];
    int l=0, r=1e6+10, ans;
    while (l<=r){
        int mid=l+r>>1;
        memset(visited, 0, sizeof visited);
        bfs(1, 1, mid);
        if (visited[n][n]==1){
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<< ans;
    return 0;
}
