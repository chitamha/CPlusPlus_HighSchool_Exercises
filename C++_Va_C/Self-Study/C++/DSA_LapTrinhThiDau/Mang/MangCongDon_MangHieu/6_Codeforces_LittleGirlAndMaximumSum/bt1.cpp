#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

int n, q, A[maxn], TS[maxn];
ll ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q;
    priority_queue<int> pq1, pq2;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        pq1.push(x);
    }
    for (int i=1; i<=q; i++){
        int l, r; cin>> l>> r;
        TS[l]++; TS[r+1]--;
    }
    for (int i=1; i<=n; i++) TS[i]+=TS[i-1], pq2.push(TS[i]); {}
    while (!pq1.empty()){
        ans+=(ll)pq1.top()*pq2.top();
        pq1.pop(); pq2.pop();
    }
    cout<< ans;
    return 0;
}
