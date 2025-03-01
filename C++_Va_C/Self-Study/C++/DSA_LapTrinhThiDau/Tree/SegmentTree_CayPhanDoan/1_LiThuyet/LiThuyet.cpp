#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;

int n, q, t, A[maxn];
long long T[4*maxn];

void build(int id, int l, int r){ //nlogn
    if (l==r){
        T[id]=A[l];
        //cout<< id<< " "<< l<< " "<< r<< " "<< T[id]<< endl;
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    T[id]=T[2*id]+T[2*id+1];
    //cout<< id<< " "<< l<< " "<< r<< " "<< T[id]<< endl;
}

long long get(int id, int l, int r, int u, int v){ //logn
    //Không giao
    if (r<u || v<l) return 0;
    //Nằm trong hoàn toàn
    // (l, r) nằm trong (u, v)
    if (l>=u && r<=v){
        //cout<< id<< " "<< l<< " "<< r<< " "<< T[id]<< endl;
        return T[id];
    }
    //Giao
    int mid=(l+r)/2;
    ll t1=get(2*id, l, mid, u, v);
    ll t2=get(2*id+1, mid+1, r, u, v);
    //cout<< id<< " "<< l<< " "<< r<< " "<< t1+t2<< endl;
    return t1+t2;
}

void update(int id, int l, int r, int pos, long long value){ //logn
    //Điều kiện này phải đầu tiên
    if (pos>r || pos<l) return;
    if (l==r){
        //l = r = pos
        T[id]=value;
        A[pos]=value;
        return;
    }
    int mid=(l+r)/2;
    update(2*id, l, mid, pos, value);
    update(2*id+1, mid+1, r, pos, value);
    T[id]=T[2*id]+T[2*id+1];
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr); cin.tie(nullptr);
    cin>> n>> q;
    for (int i=1; i<=n; i++){
        cin>> A[i];
        /*
        int x; cin>> x;
        Không cần dùng mảng cũng được
        update(1, 1, n, i, x)
        */
    }
    /*
    build(1, 1, n);
    cout<< get(1, 1, n, 2, 5)<< endl;
    update(1, 1, n, 4, 10);
    cout<< get(1, 1, n, 2, 5)<< endl;
    */
    build(1, 1, n);
    while (q--){
        cin>> t;
        if (t==1){
            int pos, v;
            cin>> pos>> v;
            update(1, 1, n, pos, v);
        } else{
            int l, r; cin>> l>> r;
            cout<< get(1, 1, n, l, r)<< endl;
        }
    }
    return 0;
}
