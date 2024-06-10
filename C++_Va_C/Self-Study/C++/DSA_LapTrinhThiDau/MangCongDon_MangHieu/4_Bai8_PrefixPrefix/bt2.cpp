#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
    int n, m, k;
    cin>> n>> m>> k;
    int A[n+5];
    vector<pair<int, pair<int, int>>> v(m+5);
    vector<int> mh(m+5, 0);
    vector<int> changes(n+5, 0);
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++)
        cin>> v[i].f>> v[i].s.f>> v[i].s.s;
    for (int i=1; i<=k; i++){
        int x, y;
        cin>> x>> y;
        mh[x]++; mh[y+1]--;
    }
    for (int i=1; i<=m; i++){
        mh[i]+=mh[i-1];
        int l=v[i].f, r=v[i].s.f;
        int k=mh[i]*(v[i].s.s);
        changes[l]+=k;
        changes[r+1]-=k;
    }
    for (int i=1; i<=n; i++){
        changes[i]+=changes[i-1];
        cout<< A[i]+changes[i]<< " ";
    }
    return 0;
}
