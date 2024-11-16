#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, k, ans=0;
vector<ll> Cost;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    Cost.resize(n+1);
    for (int i=1; i<=n; i++) cin>> Cost[i];
    deque<int> dq;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && i-dq.front()+1>k) dq.pop_front();
        while (!dq.empty() && Cost[dq.back()]>=Cost[i]) dq.pop_back();
        dq.push_back(i);
        ans+=Cost[dq.front()]*2;
    }
    cout<< ans;
    return 0;
}
