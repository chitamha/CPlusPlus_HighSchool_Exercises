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

int get(int id, int l, int r, int k){
    if (l==r) return l;
    int mid=(l+r)/2;
    if (k<=T[2*id]) return get(2*id, l, mid, k);
    else return get(2*id+1, mid+1, r, k-T[2*id]);
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
        } else cout<< get(1, 1, n, a)<< "\n";
    }
    return 0;
}
