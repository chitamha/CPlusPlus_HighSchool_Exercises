#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
using namespace std;

int n, dis[105][105], f[5], ans=1e9;

void in(int Mang[][105]){
    cout<< endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cout<< Mang[i][j]<< " ";
        cout<< endl;
    }
    cout<< endl;
}

int main(){
    freopen("qbbuild.inp", "r", stdin);
    freopen("qbbuild.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=4; i++) cin>> f[i];
    int a, b, c;
    memset(dis, 62, sizeof dis);
    for (int i=0; i<=n; i++) dis[i][i]=0;
    while (cin>> a>> b>> c){
        dis[a][b]=dis[b][a]=c;
    }
    //in(dis);
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    //in(dis);
    for (int u=1; u<=n; u++){
        for (int v=u; v<=n; v++){
            for (int i=1; i<=3; i++){
                for (int j=i+1; j<=4; j++){
                    int sum=dis[u][f[i]]+dis[u][f[j]]+dis[u][v];
                    for (int k=1; k<=4; k++){
                        if (k!=i && k!=j)
                            sum+=dis[v][f[k]];
                    }
                    ans=min(ans, sum);
                }
            }
        }
    }
    cout<< ans;
    return 0;
}
