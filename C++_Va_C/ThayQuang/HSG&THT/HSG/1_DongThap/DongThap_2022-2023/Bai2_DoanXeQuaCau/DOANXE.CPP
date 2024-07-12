#include <bits/stdc++.h>
#define maxn 1005
#define fi first
#define se second
using namespace std;

int n, p, L, W[maxn];
vector<pair<int, int>> A(maxn);
double F[maxn];

int main(){
    freopen("DOANXE.INP", "r", stdin);
    freopen("DOANXE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> p>> L;
    for (int i=1; i<=n; i++){
        cin>> A[i].fi>> A[i].se;
        W[i]=W[i-1]+A[i].fi;
    }
    F[0]=0;
    F[1]=L*1.0/A[1].se;
    //cout<< 1<< " "<< 1<< " "<< W[1]-W[0]<< endl;
    //cout<< F[1]<< endl;
    for (int i=2; i<=n; i++){
        F[i]=F[i-1]+L*1.0/A[i].se;
        int mi=A[i].se;
        for (int j=i; j>=2; j--){
            //cout<< i<< " "<< j<< " "<< W[i]-W[j-1]<< endl;
            if (W[i]-W[j-1]>p) continue;
            mi=min(mi, A[j].se);
            F[i]=min(F[i], F[j-1]+L*1.0/mi);
            //cout<< mi<< " "<< F[i]<< endl;
        }
        //cout<< F[i]<< endl;
    }
    //cout<< endl;
    cout<< fixed<< setprecision(2)<< F[n];
    return 0;
}
