#include <bits/stdc++.h>
#define maxn 105
#define fi first
#define se second
using namespace std;

int n, w;
int F[maxn][maxn], CNT[maxn];
vector<pair<int, int>> v;

int main(){
    freopen("VALY.INP", "r", stdin);
    freopen("VALY.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(F, 0, sizeof F);
    memset(CNT, 0, sizeof CNT);
    cin>> n>> w; v.resize(n+1);
    for (int i=1; i<=n; i++) cin>> v[i].se>> v[i].fi;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=w; j++){
            F[i][j]=F[i-1][j];
            if (j>=v[i].se) F[i][j]=max(F[i][j], F[i][j-v[i].se]+v[i].fi);
        }
    }
    cout<< F[n][w]<< endl;
    int i=n, j=w;
    while (F[i][j]>0){
        if (F[i][j]==F[i-1][j]) i--;
        else {
            CNT[i]++;
            j=j-v[i].se;
        }
    }
    for (int k=1; k<=n; k++)
        if (CNT[k]!=0)
            cout<< k<< " "<< CNT[k]<< endl;
    return 0;
}
