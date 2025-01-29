#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, A[100005], L[100005], R[100005], ans=1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    while (t--){
        cin>> n;
        for (ll i=1; i<=n; i++) cin>> A[i];
        deque<ll> dq;
        for (ll i=1; i<=n; i++){
            while (!dq.empty() && A[dq.back()]>=A[i]) dq.pop_back();
            if (!dq.empty()) L[i]=dq.back()+1;
            else L[i]=1;
            dq.push_back(i);
        }
        dq.clear();
        for (ll i=n; i>=1; i--){
            while (!dq.empty() && A[dq.back()]>=A[i]) dq.pop_back();
            if (!dq.empty()) R[i]=dq.back()-1;
            else R[i]=n;
            dq.push_back(i);
        }
        dq.clear();
        for (ll i=1; i<=n; i++) ans=max(ans, (R[i]-L[i]+1)*A[i]);
        cout<< ans<< endl;
        memset(A, 0, sizeof A);
        memset(R, 0, sizeof R);
        memset(L, 0, sizeof L);
        ans=1;
    }
    return 0;
}
