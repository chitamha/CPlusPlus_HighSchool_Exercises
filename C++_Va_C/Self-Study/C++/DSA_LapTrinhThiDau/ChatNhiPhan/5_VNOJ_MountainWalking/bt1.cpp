#include <bits/stdc++.h>
#define maxn 505
using namespace std;

int n, mi=1e9, ma=0;
int h[maxn][maxn], visited[maxn][maxn];
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void bfs(int x, int y, int mih, int mah){
    if (h[x][y]>mah || h[x][y]<mih) return;
    visited[x][y]=1;
    for (int k=0; k<4; k++){
        int i=x+dx[k], j=y+dy[k];
        if (i>=1 && i<=n && j>=1 && j<=n && h[i][j]<=mah && h[i][j]>=mih && visited[i][j]==0){
            bfs(i, j, mih, mah);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>> h[i][j];
            mi=min(mi, h[i][j]);
            ma=max(ma, h[i][j]);
        }
    }
    int ans=ma-mi;
    for (int mih=mi; mih<=ma; mih++){ //<=h[1][1] cung duoc
        int l=0, r=ma-mi;
        while (l<=r){
            int mid=(l+r)>>1;
            memset(visited, 0, sizeof visited);
            bfs(1, 1, mih, mih+mid);
            if (visited[n][n]==1){
                ans=min(ans, mid);
                r=mid-1;
            } else l=mid+1;
        }
    }
    cout<< ans;
    return 0;
}
