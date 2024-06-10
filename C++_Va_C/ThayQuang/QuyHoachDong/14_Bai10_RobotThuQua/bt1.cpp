#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 105
using namespace std;

int n, F[maxn], vet[maxn];
vector<pair<int, pair<int, int>>> A(maxn);

int main(){
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> A[i].fi>> A[i].se.fi;
        A[i].se.se=i;
    }
    sort(A.begin()+1, A.begin()+n+1);
    /*
    for (int i=1; i<=n; i++)
        cout<< A[i].fi<< " "<< A[i].se.fi<< " "<< A[i].se.se<< endl;
    */
    int en=1;
    for (int i=1; i<=n; i++){
        F[i]=1;
        for (int j=1; j<i; j++){
            if (A[i].se.fi>A[j].se.fi && A[i].fi!=A[j].fi && F[i]<F[j]+1){
                F[i]=F[j]+1;
                vet[i]=j;
            }
        }
        if (F[en]<F[i]) en=i;
    }
    cout<< F[en]<< endl;
    vector<int> truyvet;
    while (en>0){
        truyvet.push_back(en);
        en=vet[en];
    }
    for (int i=truyvet.size()-1; i>=0; i--){
        cout<< A[truyvet[i]].se.se<< " ";
    }
    return 0;
}
