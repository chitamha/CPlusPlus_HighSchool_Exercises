#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 100001
using namespace std;

int n, m;
vector<pair<int, int>> v;
vector<ll> F;
//F[i]: j
//Trọng lượng tối thiểu j để đạt giá trị i

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    v.resize(n+1);
    int maxv=0, ma=0;
    for (int i=1; i<=n; i++){
        cin>> v[i].se>> v[i].fi;
        maxv+=v[i].fi;
    }
    F.resize(maxv+1);
    for (int i=1; i<=maxv; i++) F[i]=1e18;
    F[0]=0;
    for (int i=1; i<=n; i++){
        for (int j=maxv; j>=v[i].fi; j--){
            F[j]=min(F[j], F[j-v[i].fi]+v[i].se);
            if (F[j]<=m) ma=max(ma, j);
        }
    }
    cout<< ma;
    return 0;
}
