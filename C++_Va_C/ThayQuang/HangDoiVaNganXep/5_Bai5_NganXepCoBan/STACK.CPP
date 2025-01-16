#include <bits/stdc++.h>
using namespace std;

int n, A[500005], L[500005], R[500005];

int main(){
    freopen("stack.inp", "r", stdin);
    freopen("stack.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    deque<int> dq;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && A[dq.back()]>=A[i]) dq.pop_back();
        if (!dq.empty()) L[i]=dq.back()+1;
        else L[i]=1;
        dq.push_back(i);
    }
    dq.clear();
    for (int i=n; i>=1; i--){
        while (!dq.empty() && A[dq.back()]>=A[i]) dq.pop_back();
        if (!dq.empty()) R[i]=dq.back()-1;
        else R[i]=n;
        dq.push_back(i);
    }
    for (int i=1; i<=n; i++) cout<< L[i]<< " "; cout<< endl;
    for (int i=1; i<=n; i++) cout<< R[i]<< " "; cout<< endl;
    return 0;
}
