#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000005
using namespace std;

int n, m, k;
ll A[maxn], L[maxn], R[maxn], D[maxn], TS[maxn];

void in(int Mang[], int l, int r, string s){
    cout<< s<< ": ";
    for (int i=l; i<=r; i++) cout<< Mang[i]<< " ";
    cout<< endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m>> k;
    int tmp;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        if (i==1) A[i]=x;
        else A[i]=x-tmp;
        tmp=x;
    }
    //in(A, 1, n, "A");
    for (int i=1; i<=m; i++) cin>> L[i]>> R[i]>> D[i];
    for (int i=1; i<=k; i++){
        int l, r; cin>> l>> r;
        TS[l]++; TS[r+1]--;
    }
    for (int i=1; i<=m; i++) TS[i]+=TS[i-1];
    //in(TS, 1, m, "TS");
    for (int i=1; i<=m; i++){
        D[i]*=TS[i];
        A[L[i]]+=D[i];
        A[R[i]+1]-=D[i];
    }
    for (int i=1; i<=n; i++) A[i]+=A[i-1], cout<< A[i]<< " "; {}
    return 0;
}
