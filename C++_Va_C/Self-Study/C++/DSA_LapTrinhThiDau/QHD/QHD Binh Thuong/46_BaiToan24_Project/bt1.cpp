#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ii pair<int, int>
#define ll long long
#define maxn 100006
using namespace std;

int n, th, lu, st, D[15], T_max=0;
//Thue; Luong; Sa thai
//T_max: so cong nhan cua thang yeu cau so cong
//nhan nhieu nhat
//F[i][j]: chi phi it nhat de thue j cong nhan vao cuoi thang
//thu i

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> th>> lu>> st;
    for (int i=1; i<=n; i++){
        cin>> D[i];
        T_max=max(T_max, D[i]);
    }
    vector<vector<int>> F(n+5, vector<int>(T_max+5, 1e9));
    vector<vector<ii>> before(n+5, vector<ii>(T_max+5, {0, 0}));
    for (int i=0; i<=n; i++) F[i][0]=0;
    for (int i=1; i<=n; i++){
        for (int j=D[i]; j<=T_max; j++){
            for (int k=D[i-1]; k<=T_max; k++){
                if (j>k && F[i][j]>F[i-1][k]+(j-k)*th+j*lu){
                    F[i][j]=F[i-1][k]+(j-k)*th+j*lu;
                    before[i][j]={i-1, k};
                }
                else if (j<k && F[i][j]>F[i-1][k]+(k-j)*st+j*lu){
                    F[i][j]=F[i-1][k]+(k-j)*st+j*lu;
                    before[i][j]={i-1, k};
                }
                else if (j==k && F[i][j]>F[i-1][k]+j*lu){
                    F[i][j]=F[i-1][k]+j*lu;
                    before[i][j]={i-1, k};
                }
            }
        }
    }
    int slMin=D[n];
    for (int i=D[n]; i<=T_max; i++)
        if (F[n][slMin]>F[n][i]) slMin=i;
    cout<< F[n][slMin]<< endl;
    //Truy vet
    vector<int> tVet(n+5, 0);
    int x=n, y=slMin;
    while (x>0){
        int u=before[x][y].fi;
        int v=before[x][y].se;
        tVet[x]=y-v;
        x=u, y=v;
    }
    for (int i=1; i<=n; i++) cout<< tVet[i]<< " ";
    return 0;
}
