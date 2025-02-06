#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
ll ans=0;
priority_queue<int> pq;

int main(){
    freopen("STADIUM.INP", "r", stdin);
    freopen("STADIUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> m>> n;
    for (int i=1; i<=m; i++){
        int x; cin>> x;
        pq.push(x);
    }
    for (int i=1; i<=n; i++){
        ans+=pq.top();
        int tmp=pq.top();
        pq.pop();
        pq.push(tmp-1);
    }
    cout<< ans;
    return 0;
}
