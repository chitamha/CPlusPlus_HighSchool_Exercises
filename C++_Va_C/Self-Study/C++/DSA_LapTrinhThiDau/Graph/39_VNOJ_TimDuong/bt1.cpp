#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

int n, mi=1e9, A[505][505], d[505][505], visited[505][505];
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

bool check(int i, int j){
    return (i>=1 && i<=n && j>=1 && j<=n);
}

void dijkstra(){
    priority_queue<llll, vector<llll>, greater<llll>> pq;
    pq.push({1, 1});
    d[1][1]=0;
    while (!pq.empty()){
        int u=pq.top().fi, v=pq.top().se;
        pq.pop();
        visited[u][v]=1;
        for (int k=0; k<4; k++){
            int i=u+dx[k], j=v+dy[k];
            if (check(i, j) && v[i][j]==0){
                d[i][j]=min(d[i][j], )
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(d, 62, sizeof d);
    cin>> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin>> A[i][j];
    dijkstra();
    cout<< d[n][n];
    return 0;
}
