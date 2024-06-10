#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 300006
using namespace std;

int n, A[maxn], ans=0;

bool check(int m){
    for (int i=1; i<m; i++){
        if (A[i]+i>A[m]+n) return false;
    }
    return true;
}

int main(){
    //freopen("FAMILIAR.INP", "r", stdin);
    //freopen("FAMILIAR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    sort(A+1, A+n+1, greater<int>());
    int l=1, r=n;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            l=mid+1;
            cout<< ans<< " ";
        } else r=mid-1;
        cout<< mid<< endl;
    }
    cout<< "Answer is "<< ans;
    return 0;
}
