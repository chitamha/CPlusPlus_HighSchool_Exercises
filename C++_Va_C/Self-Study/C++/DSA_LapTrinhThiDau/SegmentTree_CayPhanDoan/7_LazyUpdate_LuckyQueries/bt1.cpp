#include <bits/stdc++.h>
#define ll long long
#define maxn 1000006
using namespace std;

int n, q, A[maxn];
struct node{
    int anstang, ansgiam, cnt0, cnt1;
    //0=4; 1=7
    friend node operator + (node A, node B){
        node C;
        C.anstang=max({A.anstang, B.anstang, A.cnt0+B.cnt1, A.anstang+B.cnt1, A.cnt0+B.anstang});
        C.ansgiam=max({A.ansgiam, B.ansgiam, A.cnt1+B.cnt0, A.ansgiam+B.cnt0, A.cnt1+B.ansgiam});
        C.cnt0=A.cnt0+B.cnt0;
        C.cnt1=A.cnt1+B.cnt1;
        return C;
    }
};
node T[4*maxn];
int lazy[4*maxn];

void kiemtra(){
    for (int id=1; id<=4*n; id++){
        cout<< id<< " "<< T[id].anstang<< " "<< T[id].ansgiam<< " "<< T[id].cnt0<< " "<< T[id].cnt1<< endl;
    }
}

void change(int id){
    node tmp;
    tmp.cnt0=T[id].cnt1;
    tmp.cnt1=T[id].cnt0;
    tmp.anstang=T[id].ansgiam;
    tmp.ansgiam=T[id].anstang;
    T[id]=tmp;
}

void push(int id){
    if (lazy[id]==1){
        change(2*id); change(2*id+1);
        lazy[2*id]^=lazy[id];
        lazy[2*id+1]^=lazy[id];
        lazy[id]=0;
    }
};

void build(int id, int l, int r){
    if (l==r){
        if (A[l]==1) T[id]={1, 1, 0, 1};
        else T[id]={1, 1, 1, 0};
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[id*2]+T[id*2+1];
}

void update(int id, int l, int r, int u, int v){
    if (u>r || v<l) return;
    if (u<=l && r<=v){
        change(id);
        lazy[id]^=1;
        return;
    }
    int mid=(l+r)/2;
    push(id);
    update(2*id, l, mid, u, v);
    update(2*id+1, mid+1, r, u, v);
    T[id]=T[id*2]+T[id*2+1];
}

node get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return {0, 0, 0};
    if (u<=l && r<=v) return T[id];
    int mid=(l+r)/2;
    push(id);
    return get(2*id, l, mid, u, v)+get(2*id+1, mid+1, r, u, v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> q; cin.ignore();
    string s; cin>> s; s=' '+s;
    for (int i=1; i<=n; i++){
        if (s[i]=='4') A[i]=0;
        else A[i]=1;
    }
    build(1, 1, n);
    while (q--){
        string s1; cin>> s1;
        if (s1=="count") cout<< get(1, 1, n, 1, n).anstang<< "\n";
        else{
            int l, r; cin>> l>> r;
            update(1, 1, n, l, r);
        }
    }
    //kiemtra();
    return 0;
}
