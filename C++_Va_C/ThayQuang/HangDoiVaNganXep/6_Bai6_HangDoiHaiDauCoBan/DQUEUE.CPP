#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, m, A[100005];
vector<vector<int>> Tv(100005);

int main(){
    freopen("dqueue.inp", "r", stdin);
    freopen("dqueue.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++){
        int st, en;
        cin>> st>> en;
        Tv[en].push_back(st);
    }
    deque<int> dq;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && A[dq.back()]>=A[i]) dq.pop_back();
        dq.push_back(i);
        for (int j:Tv[i]){
            while (!dq.empty() && dq.front()<j) dq.pop_front();
            cout<< A[dq.front()]<< endl;
        }
    }
    return 0;
}
