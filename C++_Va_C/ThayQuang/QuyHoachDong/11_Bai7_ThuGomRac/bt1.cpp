#include <bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;

int n, m;
int A[maxn][maxn], F[maxn][maxn];

int main(){
    freopen("GARBAGE.INP", "r", stdin);
    freopen("GARBAGE.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>> A[i][j];
        }
    }
    for (int j=1; j<=m; j++) F[1][j]=A[1][j];
    for (int i=2; i<=n; i++){
        for (int j=1; j<=m; j++){
            F[i][j]=max({F[i-1][j-1], F[i-1][j], F[i-1][j+1]})+A[i][j];
        }
    }
    /*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) cout<< F[i][j]<< " ";
        cout<< endl;
    }
    */
    int Ma=0, en;
    for (int j=1; j<=m; j++){
        if (F[n][j]>=Ma){
            Ma=F[n][j];
            en=j;
        }
    }
    cout<< Ma<< endl;
    vector<int> v;
    int i=n, j=en;
    v.push_back(en);
    while (i>=2){
        if (F[i-1][j]+A[i][j]==F[i][j]){
            v.push_back(j);
        } else if (F[i-1][j-1]+A[i][j]==F[i][j]){
            v.push_back(j-1);
            j--;
        } else{
            v.push_back(j+1);
            j++;
        }
        i--;
    }
    for (int i=v.size()-1; i>=0; i--) cout<< v[i]<< endl;
    return 0;
}
