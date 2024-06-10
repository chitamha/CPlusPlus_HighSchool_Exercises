#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<int> A, B;

int main(){
    freopen("FIND.INP", "r", stdin);
    freopen("FIND.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>> n>> m;
    A.resize(n+1); B.resize(m+1);
    for (int i=1; i<=n; i++) cin>> A[i];
    for (int i=1; i<=m; i++) cin>> B[i];
    int l1=1, l2=1;
    int cnt=0;
    while (l1<=n && l2<=m){
        if (A[l1]<B[l2]){
            cnt++;
            l1++;
        } else{
            cout<< cnt<< " ";
            l2++;
        }
    }
    while (l2<=m){
        cout<< cnt<< " ";
        l2++;
    }
    return 0;
}
