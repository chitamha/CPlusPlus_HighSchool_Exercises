#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, K, ans=0;
vector<ll> A;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> K;
    for (int i=1; i<=n; i++){
        ll x; cin>> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    for (int i=0; i<n; i++)
        ans+=upper_bound(A.begin()+i+1, A.end(), K-A[i])-lower_bound(A.begin()+i+1, A.end(), K-A[i]);
    cout<< ans;
    return 0;
}
