#include <bits/stdc++.h>
#define maxn 305
using namespace std;

int m, n, k;
string s;
char A[maxn][maxn];
int d[maxn][maxn][maxn];
int visited[maxn][maxn][maxn];
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};
struct state{
    int x, y, z;
};
queue<state> q;

bool ingrid(int i, int j){
    return i>=1 && i<=m && j>=1 && j<=n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n>> k; cin.ignore();
    cin>> s; s=' '+s;
    memset(d, 62, sizeof d);
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin>> A[i][j];
            q.push({i, j, 0});
            d[i][j][0]=0;
        }
    }
    while (!q.empty()){
        auto tmp=q.front(); q.pop();
        int u=tmp.x, v=tmp.y, w=tmp.z;
        if (w==k) return cout<< d[u][v][w], 0;
        if (visited[u][v][w]) continue;
        visited[u][v][w]=1;
        for (int k=0; k<4; k++){
            int a=u+dx[k], b=v+dy[k], c=w;
            if (A[a][b]==s[w+1]){
                //Nếu đỉnh (a, b, c) đến được (a−1, b, c+1) thì ta sẽ không xét
                //đến đỉnh (a−1, b, c), tương tự cho ba hướng còn lại
                //...
                c++;
            }
            if (!ingrid(a, b) || visited[a][b][c]) continue;
            if (d[a][b][c]>d[u][v][w]+1){
                d[a][b][c]=d[u][v][w]+1;
                q.push({a, b, c});
            }
        }
    }
    return 0;
}
