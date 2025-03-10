#include <bits/stdc++.h>
#define MOD 65536
#define ll long long
using namespace std;

ll seed, mul, add, n, k, ans=0, A[250005];
multiset<ll> mse;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    for (ll q=1; q<=t; q++){
        cin>> seed>> mul>> add>> n>> k;
        A[1]=seed;
        for (ll i=2; i<=n; i++) A[i]=(A[i-1]*mul+add)%MOD;
        for (ll i=1; i<=k; i++) mse.insert(A[i]);
        auto it=mse.begin();
        for (ll i=2; i<=(k+1)/2; i++) it++;
        ans+=*it;
        for (ll i=k+1; i<=n; i++){
            auto en=mse.end(); en--;
            if (A[i-k]<=*it && k%2==0 && it!=en) it++;
            if (A[i-k]>=*it && k%2==1 && it!=mse.begin()) it--;
            mse.erase(mse.lower_bound(A[i-k]));
            mse.insert(A[i]);
            en=mse.end(); en--;
            if (A[i]<=*it && k%2==0 && it!=mse.begin()) it--;
            if (A[i]>=*it && k%2==1 && it!=en) it++;
            ans+=*it;
        }
        cout<< "Case #"<< q<< ": "<< ans<< "\n";
        mse.clear();
        ans=0;
        memset(A, 0, sizeof A);
    }
    return 0;
}
