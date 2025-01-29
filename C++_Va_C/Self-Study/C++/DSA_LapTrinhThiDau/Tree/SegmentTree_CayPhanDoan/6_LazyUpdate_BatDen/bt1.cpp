#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;

int n, m, lazy[4*maxn];
struct light{
    int on, off;
    friend light operator + (light A, light B){
        light C;
        C.on=A.on+B.on; C.off=A.off+B.off;
        return C;
    }
};
light T[4*maxn];

light reverse_light(light A){
    light B;
    B.on=A.off; B.off=A.on;
    return B;
}

void build(int id, int l, int r){
    if (l==r){
        T[id].on=0;
        T[id].off=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[2*id]+T[2*id+1];
}

void push(int id){
    if (lazy[id]==1){
        T[2*id]=reverse_light(T[2*id]);
        T[2*id+1]=reverse_light(T[2*id+1]);
        lazy[2*id]^=lazy[id];
        lazy[2*id+1]^=lazy[id];
        lazy[id]=0;
    }
}

void update(int id, int l, int r, int u, int v){
    if (u>r || v<l) return;
    if (u<=l && r<=v){
        T[id]=reverse_light(T[id]);
        lazy[id]^=1;
        return;
    }
    int mid=(l+r)/2;
    push(id);
    update(2*id, l, mid, u, v);
    update(2*id+1, mid+1, r, u, v);
    T[id]=T[id*2]+T[id*2+1];
}

light get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return {0, 0};
    if (u<=l && r<=v) return T[id];
    int mid=(l+r)/2;
    push(id);
    return get(2*id, l, mid, u, v)+get(2*id+1, mid+1, r, u, v);
}

int main(){
    cin>> n>> m;
    build(1, 1, n);
    while (m--){
        int t, s, e;
        cin>> t>> s>> e;
        if (t==0) update(1, 1, n, s, e);
        else cout<< get(1, 1, n, s, e).on<< "\n";
    }
    return 0;
}
