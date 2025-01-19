#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> A;
deque<int> dq;

int main(){
    freopen("MINIMUM.INP", "r", stdin);
    freopen("MINIMUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    A.resize(n+5);
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=n; i++){
        while (!dq.empty() && A[i]<=A[dq.back()]) dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && dq.front()<i-k+1) dq.pop_front();
        if (i>=k) cout<< A[dq.front()]<< endl;
    }
    return 0;
}
