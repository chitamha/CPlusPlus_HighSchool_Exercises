#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, A[55][55];
vector<int> d[55][55];
int dx[]={1, 0, 0, -1, 0};
int dy[]={0, -1, 1, 0, 0};

bool ingrid(int i, int j){
    return i>=1 && j>=1 && i<=n && j<=m;
}

int get(int x, int tim){
    tim%=4;
    while (tim--){
        if (x==0) x=3;
        else x--;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>> A[i][j], d[i][j].push_back(1e7);
    d[n][1].push_back(0);
    for (int i=n; i>=1; i--){
        for (int j=1; j<=m; j++){
            for (int dis:d[i][j]){
                for (int k=0; k<5; k++){
                    int u=i+dx[k], v=j+dy[k];
                    if (!ingrid(u, v)) continue;
                    if (get(A[u][v], dis+1)!=0){
                        d[u][v].push_back(dis+1);
                    }
                }
            }
            cout<< "("<< i<< "; "<< j<< ") ";
            for (int dis:d[i][j]) cout<< dis<< " ";
            cout<< endl;
        }
    }
    int ans=1e9;
    for (int dis:d[1][m]) ans=min(ans, dis), cout<< dis<< " "; {}
    cout<< endl;
    cout<< ans;
    return 0;
}
