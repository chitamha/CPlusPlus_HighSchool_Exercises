#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, L[maxn], R[maxn];
vector<int> h(maxn, 0);

int main(){
    cin>> n;
    for (int i=1; i<=n; i++) cin>> h[i];
    deque<int> dq;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && h[dq.back()]>=h[i]) dq.pop_back();
        if (!dq.empty()) L[i]=dq.back()+1;
        else L[i]=1;
        dq.push_back(i);
    }
    dq.clear();
    for (int i=n; i>=1; i--){
        while (!dq.empty() && h[dq.back()]>=h[i]) dq.pop_back();
        if (!dq.empty()) R[i]=dq.back()-1;
        else R[i]=n;
        dq.push_back(i);
    }
    int ans=0;
    for (int i=1; i<=n; i++){
        if (R[i]-L[i]+1>=h[i]) ans=max(ans, h[i]);
    }
    cout<< ans;
    return 0;
}
