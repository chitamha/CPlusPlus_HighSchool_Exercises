#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 15006
using namespace std;

int n, k, A[maxn], ans;

bool check(int M){
    int l=1, cnt=0, sum=0;
    while (l<=n){
        sum+=A[l];
        if (sum>M){
            cnt++;
            sum=A[l];
        } else if (sum==M){
            cnt++;
            sum=0;
        }
        l++;
    }
    if (sum!=0) cnt++;
    return cnt<=k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> k;
    for (int i=1; i<=n; i++) cin>> A[i];
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
