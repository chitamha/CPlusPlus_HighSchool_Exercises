#include <bits/stdc++.h>
#define maxn 100006
#define inf 1e9+10
#define ll long long
#define fi first
#define se second
using namespace std;

int n, x, k;
ll V[maxn], ans=0;
vector<pair<int, int>> A;

int tknp1(int x, int left, int right){
    int l=left, r=right;
    while (l<=r){
        int mid=(l+r)/2;
        if (A[mid].fi>=x) r=mid-1;
        else l=mid+1;
    }
    return r+1;
}

int tknp2(int x, int left, int right){
    int l=left, r=right;
    while (l<=r){
        int mid=(l+r)/2;
        if (A[mid].fi<=x) l=mid+1;
        else r=mid-1;
    }
    return l-1;
}

int main(){
    freopen("MARIO.INP", "r", stdin);
    freopen("MARIO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> x>> k; A.resize(n+10);
    for (int i=1; i<=n; i++) cin>> A[i].fi>> A[i].se;
    sort(A.begin()+1, A.begin()+1+n);
    for (int i=1; i<=n; i++) V[i]=V[i-1]+1ll*A[i].se;
    int idex1=tknp1(x-k, 1, n), idex2=tknp2(x+k, 1, n);
    for (int i=idex1; i<=idex2; i++){
        int id;
        if (A[i].fi<x){
            id=tknp2(2*A[i].fi+k-x, idex1, idex2);
            ans=max(ans, V[id]-V[i-1]);
        } else{
            id=tknp1(2*A[i].fi-k-x, idex1, idex2);
            ans=max(ans, V[i]-V[id-1]);
        }
    }
    cout<< ans;
    return 0;
}
