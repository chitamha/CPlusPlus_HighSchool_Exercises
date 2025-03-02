#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;

int n, q, A[maxn], Bit1[maxn], Bit2[maxn];

void updatePoint(int pos, int val, int Bit[]){
    for (; pos<=n; pos+=pos&(-pos))
        Bit[pos]+=val;
}

void updateRange(int l, int r, int val){
    updatePoint(l, val, Bit2);
    updatePoint(r+1, -val, Bit2);
    updatePoint(l, (n-l+1)*val, Bit1);
    updatePoint(r+1, -(n-r)*val, Bit1);
}

int get(int pos, int Bit[]){
    int sum=0;
    for (; pos>=1; pos-=pos&(-pos))
        sum+=Bit[pos];
    return sum;
}

int preS(int pos){
    return Bit1[pos]-Bit2[pos]*(n-pos);
}

int sumRange(int l, int r){
    return preS(r)-preS(l-1);
}

int Find(int x){
    int l=1, r=n, mid;
    while (l<=r){
        mid=(l+r)/2;
        if (get(mid, Bit2)>=x) r=mid-1;
        else l=mid+1;
    }
    return r+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    sort(A+1, A+n+1);
    for (int i=1; i<=n; i++) updateRange(i, i, A[i]);
    cin>> q;
    while (q--){
        int x; cin>> x;
        int pos=Find(x);
        cout<< n-pos+1<< "\n";
        updateRange(pos, n, -1);
    }
    return 0;
}
