#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

int n, A[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    deque<int> dq;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && A[i]<=A[dq.back()]) dq.pop_back();
        if (dq.empty()) cout<< 0<< " ";
        else cout<< dq.back() << " ";
        dq.push_back(i);
    }
    return 0;
}
