#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define maxn 105
using namespace std;

int n, q, M[maxn], C[maxn], Slmax=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    for (int i=1; i<=n; i++){
        cin>> M[i];
        Slmax=max(Slmax, M[i]);
    }
    for (int i=1; i<=n; i++) cin>> C[i];
    vector<vector<int>> F(n+5, vector<int>(Slmax+5, 1e9));
    vector<vector<ii>> before(n+5, vector<ii>(Slmax+5, {0, 0}));
    for (int i=0; i<=n; i++) F[i][0]=0;
    for (int i=1; i<=n; i++){
        for (int j=M[i]; j<=Slmax; j++){
            for (int k=M[i-1]; k<=Slmax; k++){
                int thua=k-M[i-1];
                if (j>thua && F[i][j]>F[i-1][k]+(j-thua)*C[i]+thua*q){
                    F[i][j]=F[i-1][k]+(j-thua)*C[i]+thua*q;
                    before[i][j]={i-1, k};
                } else if (j<=thua && F[i][j]>F[i-1][k]+thua*q){
                    F[i][j]=F[i-1][k]+thua*q;
                    before[i][j]={i-1, k};
                }
            }
        }
    }
    int idMin=M[n];
    for (int i=M[n]; i<=Slmax; i++) if (F[n][i]<F[n][idMin]) idMin=i;
    cout<< F[n][idMin]<< endl;
    //Truy vet
    vector<int> tVet(n+5, 0);
    int x=n, y=idMin;
    while (x>0){
        int u=before[x][y].fi;
        int v=before[x][y].se;
        tVet[x]=max(0, y-v);
        x=u, y=v;
    }
    for (int i=1; i<=n; i++) cout<< tVet[i]<< " ";
    return 0;
}
