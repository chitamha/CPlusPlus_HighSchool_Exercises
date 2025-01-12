#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 50006
using namespace std;

int n, k, X[maxn], ans;

bool check(int dis){
    int cnt=0, id=1;
    while (cnt<k){
        cnt++;
        id=upper_bound(X+1, X+n+1, X[id]+2*dis)-X;
        if (id==n+1) return 1;
    }
    return 0;
}

int main(){
    //freopen("ANGRY.INP", "r", stdin);
    //freopen("ANGRY.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> X[i];
    sort(X+1, X+n+1);
    int l=0, r=1e9;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<< ans;
    return 0;
}
