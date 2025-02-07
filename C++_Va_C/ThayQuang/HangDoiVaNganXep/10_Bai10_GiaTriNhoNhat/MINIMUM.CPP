#include <bits/stdc++.h>
using namespace std;

int n, k, A[1000005];
deque<int> dq;

int main(){
    freopen("MINIMUM.INP", "r", stdin);
    freopen("MINIMUM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        while (!dq.empty() && A[i]<=A[dq.back()]) dq.pop_back();
        dq.push_back(i);
        while (!dq.empty() && dq.front()<i-k+1) dq.pop_front();
        if (i>=k) cout<< A[dq.front()]<< "\n";
    }
    return 0;
}
