#include <bits/stdc++.h>
#define maxn 100006
#define ll long long
using namespace std;

int n, k, A[maxn];
vector<int> T[4*maxn];

void build(int id, int l, int r){
    if (l==r){
        T[id].push_back(A[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    int n1=T[2*id].size(), n2=T[2*id+1].size();
    int i=0, j=0;
    while (i<n1 && j<n2){
        if (T[2*id][i]>T[2*id+1][j]) T[id].push_back(T[2*id+1][j++]);
        else T[id].push_back(T[2*id][i++]);
    }
    while (i<n1) T[id].push_back(T[2*id][i++]);
    while (j<n2) T[id].push_back(T[2*id+1][j++]);
}

int get(int id, int l, int r, int u, int v, int value){
    if (u>r || v<l) return 0;
    if (u<=l && r<=v){
        auto it=upper_bound(T[id].begin(), T[id].end(), value);
        if (it==T[id].begin()) return 0;
        else return it-T[id].begin();
    }
    int mid=(l+r)/2;
    return get(2*id, l, mid, u, v, value)+get(2*id+1, mid+1, r, u, v, value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> A[i], A[i]-=k, A[i]+=A[i-1]; {}
    build(1, 1, n);
    ll ans=0;
    //for (int i=1; i<=n; i++) cout<< A[i]<< " ";
    for (int i=1; i<=n; i++){
        if (A[i]>=0) ans++;
        ans+=get(1, 1, n, 1, i-1, A[i]);
    }
    cout<< ans;
    return 0;
}
