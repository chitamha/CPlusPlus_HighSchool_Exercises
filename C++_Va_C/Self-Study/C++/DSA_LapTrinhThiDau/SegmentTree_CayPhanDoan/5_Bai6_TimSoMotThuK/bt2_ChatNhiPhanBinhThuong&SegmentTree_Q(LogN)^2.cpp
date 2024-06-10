#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int n, q, A[maxn], T[maxn];

void update(int id, int l, int r, int pos, int value){
    if (l>pos || r<pos) return;
    if (l==r){
        A[pos]=value;
        T[id]=value;
        return;
    }
    int mid=(l+r)/2;
    update(2*id, l, mid, pos, value);
    update(2*id+1, mid+1, r, pos, value);
    T[id]=T[2*id]+T[2*id+1];
}

int get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return T[id];
    int mid=(l+r)/2;
    return get(2*id, l, mid, u, v)+get(2*id+1, mid+1, r, u, v);
}

int cnp(int cnt){
    int l=1, r=n;
    int ans=n+1;
    while (l<=r){
        int mid=(l+r)/2;
        if (get(1, 1, n, 1, mid)>=cnt){
            ans=min(mid, ans);
            r=mid-1;
        } else l=mid+1;
    }
    return ans;
}

int main(){
    cin>> n>> q;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        update(1, 1, n, i, A[i]);
    }
    while (q--){
        int type, a;
        cin>> type>> a;
        if (type==1){
            //A[a]^=1; update(1, 1, n, a, A[a]);
            if (A[a]==1) update(1, 1, n, a, 0);
            else update(1, 1, n, a, 1);
        } else cout<< cnp(a)<< "\n";
    }
    return 0;
}
