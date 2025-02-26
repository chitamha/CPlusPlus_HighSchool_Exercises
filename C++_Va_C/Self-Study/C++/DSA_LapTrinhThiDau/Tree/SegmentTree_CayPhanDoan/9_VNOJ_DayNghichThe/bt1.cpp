#include <bits/stdc++.h>
#define maxn 60006
using namespace std;

int n, A[maxn], ans=0;
vector<int> T[maxn*4];

void build(int id, int l, int r){
    if (l==r){
        T[id].push_back(A[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    for (int x:T[2*id]) T[id].push_back(x);
    for (int x:T[2*id+1]) T[id].push_back(x);
    sort(T[id].begin(), T[id].end());
}

int get(int id, int l, int r, int u, int v, int x){
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return lower_bound(T[id].begin(), T[id].end(), x)-T[id].begin();
    int mid=(l+r)/2;
    return get(2*id, l, mid, u, v, x)+get(2*id+1, mid+1, r, u, v, x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    build(1, 1, n);
    for (int i=1; i<n; i++) ans+=get(1, 1, n, i+1, n, A[i]);
    cout<< ans;
    return 0;
}
