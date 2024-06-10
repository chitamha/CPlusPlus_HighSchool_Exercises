#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
ll ans=0;
vector<int> A, B;

ll XuLi(int &left, int Size, vector<int> v){
    int cnt=1;
    while (v[left]==v[left+1] && left+1<=Size){
        cnt++;
        left++;
    }
    left++;
    return cnt;
}

int main(){
    freopen("SUM.INP", "r", stdin);
    freopen("SUM.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    A.resize(n+1); B.resize(m+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++) cin>> B[i];
    int l1=1, l2=1;
    while (l1<=n && l2<=m){
        if (A[l1]==B[l2]){
            ans+=XuLi(l1, n, A)*XuLi(l2, m, B);
        } else{
            if (A[l1]<B[l2]) l1++;
            else l2++;
        }
    }
    cout<< ans;
    return 0;
}
