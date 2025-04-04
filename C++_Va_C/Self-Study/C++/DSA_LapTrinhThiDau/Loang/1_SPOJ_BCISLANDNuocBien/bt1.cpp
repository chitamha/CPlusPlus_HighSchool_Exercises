#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1005
using namespace std;

int n, m, h[maxn][maxn], visited[maxn][maxn], cas=0;
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void loang(int i, int j, int hi){
    visited[i][j]=1;
    for (int k=0; k<4; k++){
        int u=i+dx[k];
        int v=j+dy[k];
        if (u>=1 && u<=n && v>=1 && v<=m && visited[u][v]==0 && h[u][v]<=hi) loang(u, v, hi);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (1){
        memset(h, 0, sizeof h);
        memset(visited, 0, sizeof visited);
        cin>> n>> m;
        if (n==0 && m==0) return 0;
        int himax=0, check=0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cin>> h[i][j];
                himax=max(himax, h[i][j]);
            }
        }
        for (int height=0; height<=himax; height++){
            int cnt=0;
            //cout<< height<< endl;
            /*
            for (int i=1; i<=n; i++){
                for (int j=1; j<=m; j++){
                    if (visited[i][j]==0 && h[i][j]==0)
                        loang(i, j, height);
                }
            }
            */
            for (int i=1; i<=n; i++){
                int j=1;
                if (visited[i][j]==0 && h[i][j]<=height)
                    loang(i, j, height);
                j=m;
                if (visited[i][j]==0 && h[i][j]<=height)
                    loang(i, j, height);
            }
            for (int j=1; j<=m; j++){
                int i=1;
                if (visited[i][j]==0 && h[i][j]<=height)
                    loang(i, j, height);
                i=n;
                if (visited[i][j]==0 && h[i][j]<=height)
                    loang(i, j, height);
            }
            /*
            cout<< height<< endl;
            for (int i=1; i<=n; i++){
                for (int j=1; j<=m; j++) cout<< (visited[i][j]!=1)<< " ";
                cout<< endl;
            }
            */
            for (int i=1; i<=n; i++){
                for (int j=1; j<=m; j++){
                    if (visited[i][j]==0){
                        loang(i, j, 1e9);
                        cnt++;
                    }
                }
            }
            if (cnt>=2){
                check=1;
                cout<< "Case "<< ++cas<< ": Island splits when ocean rises "<< height<< " feet."<< endl;
                //break;
            }
            memset(visited, 0, sizeof visited);
        }
        if (!check) cout<< "Case "<< ++cas<< ": Island never splits."<< endl;
    }
    return 0;
}
