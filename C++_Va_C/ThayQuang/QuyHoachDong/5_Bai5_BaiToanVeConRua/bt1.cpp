#include <bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;

int n, m;
int A[maxn][maxn], F[maxn][maxn];

int main(){
    freopen("CONRUA.INP", "r", stdin);
    freopen("CONRUA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>> A[i][j];
        }
    }
    vector<pair<int, int>> v;
    for (int j=1; j<=m; j++){
        for (int i=n; i>=1; i--){
            F[i][j]=max(F[i+1][j], F[i][j-1])+A[i][j];
        }
    }
    cout<< F[1][m]<< endl;
    int i=1, j=m;
    v.push_back({i, j});
    while (!(i==n && j==1)){
        if (F[i+1][j]+A[i][j]==F[i][j]){
            v.push_back({i+1, j});
            i=i+1;
        } else{
            v.push_back({i, j-1});
            j=j-1;
        }
    }
    for (auto it=v.rbegin(); it!=v.rend(); it++){
        cout<< "("<< (*it).first<< ","<< (*it).second<< ") ";
        if (it!=v.rend()-1) cout<< "=> ";
    }
    return 0;
}
