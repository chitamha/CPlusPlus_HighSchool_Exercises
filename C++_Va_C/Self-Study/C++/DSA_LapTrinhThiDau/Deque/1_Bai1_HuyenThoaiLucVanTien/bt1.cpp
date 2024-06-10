#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> A;

int main(){
    int t; cin>> t;
    while (t--){
        cin>> n>> k; A.resize(n+5);
        deque<int> dq;
        for (int i=1; i<=n; i++) cin>> A[i];
        for (int i=1; i<=n; i++){
            while (!dq.empty() && A[dq.back()]>=A[i]) dq.pop_back();
            if (dq.front()+k<=i) dq.pop_front();
            if (i>=k) cout<< A[dq.front()]<< " ";
        }
        cout<< endl;
        A.clear();
    }
    return 0;
}
