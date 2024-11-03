#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, l, r;
vector<ll> A;

ll process(ll siz){
    map<ll, ll> mp;
    ll it1=1, it2=1, ans=0;
    while (it2<=n){
        mp[A[it2]]++;
        while (mp.size()>siz && it1<=it2){
            if (mp[A[it1]]==1) mp.erase(A[it1]);
            else mp[A[it1]]--;
            it1++;
        }
        if (mp.size()<=siz) ans+=it2-it1+1;
        it2++;
        //cout<< ans<< " "<< it1<< " "<< it2-1<< endl;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> l>> r;
    A.resize(n+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    //cout<< process(r)<< endl;
    //cout<< process(r)-process(l-1)<< " "<< process(r)<< " "<< process(l-1);
    cout<< process(r)-process(l-1);
    return 0;
}
